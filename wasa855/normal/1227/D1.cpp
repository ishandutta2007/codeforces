#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int lowbit(int x)
{
	return x&(-x);
}
int n;
int t[N*4],a[N];
int ans[N];
struct Node
{
	int val,pl;
};
Node b[N];
struct Query
{
	int k,p,id;
};
Query q[N];
bool cmp2(Query x,Query y)
{
	return x.k<y.k;
}
bool cmp(Node x,Node y)
{
	if(x.val!=y.val) return x.val>y.val;
	return x.pl<y.pl;
}
void update(int u,int l,int r,int p)
{
	if(l==r)
	{
		t[u]=1;
		return ;
	}
	int mid=(l+r)/2;
	if(p<=mid) update(u*2,l,mid,p);
	else update(u*2+1,mid+1,r,p);
	t[u]=t[u*2]+t[u*2+1];
}
int query(int u,int l,int r,int k)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	if(k<=t[u*2]) return query(u*2,l,mid,k);
	else return query(u*2+1,mid+1,r,k-t[u*2]);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i].pl=i,b[i].val=a[i];
	}
	sort(b+1,b+n+1,cmp);
	int m=read();
	for(int i=1;i<=m;i++)
	{
		q[i].id=i;
		q[i].k=read(),q[i].p=read();
	}
	sort(q+1,q+m+1,cmp2);
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		while(cur<q[i].k)
		{
			cur++;
			update(1,1,n,b[cur].pl);
		}
		ans[q[i].id]=a[query(1,1,n,q[i].p)];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}