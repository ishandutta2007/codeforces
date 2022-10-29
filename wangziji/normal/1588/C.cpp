#include <bits/stdc++.h>
#define int long long
using namespace std;
struct stree
{
	int l,r,mn,add,cnt;
}t[2][550005];
inline stree mer(stree x,stree y)
{
	stree rtn;
	rtn.l=x.l,rtn.r=y.r;
	rtn.mn=min(x.mn,y.mn);
	rtn.add=rtn.cnt=0;
	if(rtn.mn==x.mn) rtn.cnt+=x.cnt;
	if(rtn.mn==y.mn) rtn.cnt+=y.cnt;
//	cout << rtn.cnt << "cnt\n";
	return rtn;
}
inline void build(int now,int l,int r,int k)
{
//	cout << now << "               "<< l << " " << r << "nmd\n";
	t[k][now].l=l,t[k][now].r=r,t[k][now].add=0;
	if(l==r)
	{
		t[k][now].mn=0,t[k][now].cnt=1;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid,k),build(now*2+1,mid+1,r,k);
	t[k][now]=mer(t[k][now*2],t[k][now*2+1]);
}
inline void give(int now,int k,int x)
{
	t[k][now].mn+=x,t[k][now].add+=x;
}
inline void pd(int now,int k)
{
	if(t[k][now].l!=t[k][now].r)
	{
		give(now*2,k,t[k][now].add);
		give(now*2+1,k,t[k][now].add);
		t[k][now].add=0;
	}
}
inline void change(int now,int l,int r,int k,int x)
{
//	cout << now << " " << l << " " << r << " " << t[k][now].l << " " << t[k][now].r<< "\n";
	pd(now,k);
	if(t[k][now].l==l&&t[k][now].r==r)
	{
		give(now,k,x);
		return ;
	}
	if(t[k][now*2].r>=r) change(now*2,l,r,k,x);
	else if(t[k][now*2+1].l<=l) change(now*2+1,l,r,k,x);
	else change(now*2,l,t[k][now*2].r,k,x),change(now*2+1,t[k][now*2+1].l,r,k,x);
	
	t[k][now].mn=min(t[k][now*2+1].mn,t[k][now*2].mn);
	t[k][now].cnt=0;
	if(t[k][now].mn==t[k][now*2+1].mn) t[k][now].cnt+=t[k][now*2+1].cnt;
	if(t[k][now].mn==t[k][now*2].mn) t[k][now].cnt+=t[k][now*2].cnt;
}
inline stree query(int now,int l,int r,int k)
{
	if(r<l) return {0,0,0,0,0};
	pd(now,k);
	if(t[k][now].l==l&&t[k][now].r==r) return t[k][now];
	if(t[k][now*2].r>=r) return query(now*2,l,r,k);
	else if(t[k][now*2+1].l<=l) return query(now*2+1,l,r,k);
	else return mer(query(now*2,l,t[k][now*2].r,k),query(now*2+1,t[k][now*2+1].l,r,k));
}
inline int ask(int now,int k)
{
/*	if(k==1)
	{
		cout << t[k][now].l << " " << t[k][now].r << " "<< t[k][now].mn << ":*\n";
	}*/
	if(t[k][now].l==t[k][now].r)
	{
		if(t[k][now].mn>=0) return 1e9;
		return t[k][now].l-1;
	}
	pd(now,k);
	if(t[k][now*2].mn<0) return ask(now*2,k);
	return ask(now*2+1,k);
}
int a[300005];
//int t[300005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		if(n==1)
		{
			cout << (a[1]==0) << "\n";
			continue;
		}
		build(1,1,n/2,0),build(1,1,(n+1)/2,1);
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			int f=1;
		/*	for(int j=i;j<=n;j++)
			{
				t[j]+=f*a[i];
				f*=-1;
			}*/
			int l=i,r=n;
			if(l%2==0)
			{
				change(1,l/2,n/2,0,a[i]);
				if(l!=n)change(1,(l+1)/2+1,(n+1)/2,1,-a[i]);
			}
			else
			{
				if(l!=n) change(1,l/2+1,n/2,0,-a[i]);
				change(1,(l+1)/2,(n+1)/2,1,a[i]);
			}
			int p2=ask(1,0),p1=ask(1,1);
			p1=p1*2-1,p2*=2;
			++p1,++p2;
			p2=p1=min(n,min(p1,p2));
			if(p1%2==0) --p1;
			if(p2%2==1) --p2;
			int l1=i,l2=i;
			if(l1%2==0) ++l1;
			if(l2%2==1) ++l2;
			l1=(l1+1)/2,l2=l2/2;
			p1=(p1+1)/2,p2=p2/2;
			stree x,y;
			if(p1<l1) x={0,0,0,0,0};
			else x=query(1,l1,p1,1);
			if(p2<l2) y={0,0,0,0,0};
			else y=query(1,l2,p2,0);
			if(x.mn==0) ans+=x.cnt;
			if(y.mn==0) ans+=y.cnt;
		}
		cout << ans << "\n";
	}
	return 0;
}