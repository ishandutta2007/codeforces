#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
struct Ant
{
	int s,old_id,f;
	char d;
}a[max_n];
inline bool operator < (const Ant &p,const Ant &q)
{
	return p.s<q.s;
}
inline int count(vector<int> &v,int l,int r)
{
	return upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
}
int id[max_n],ans[max_n];
int main()
{
	int n,m;
	long long t;
	scanf("%d%d%lld",&n,&m,&t);
	vector<int> pL,pR;
	for(int i=0;i<n;++i)
	{
		char ch[4];
		scanf("%d%s",&a[i].s,ch);
		if(a[i].s==m)
			a[i].s=0;
		a[i].d=ch[0];
		if(ch[0]=='L')
		{
			a[i].f=(a[i].s-t)%m;
			a[i].f+=a[i].f<0?m:0;
			pL.push_back(a[i].s);
			pL.push_back(a[i].s+m);
		}
		else
		{
			assert(ch[0]=='R');
			a[i].f=(a[i].s+t)%m;
			pR.push_back(a[i].s);
			pR.push_back(a[i].s+m);
		}
		a[i].old_id=i;
	}
	sort(a,a+n);
	sort(pL.begin(),pL.end());
	sort(pR.begin(),pR.end());
	int q=(t<<1)/m%n,r=(t<<1)%m;
	int vL=1ll*q*(int)pR.size()/2%n;
	int vR=1ll*q*(int)pL.size()/2%n;
	for(int i=0;i<n;++i)
	{
		if(a[i].d=='L')
			id[i]=(i-vL-count(pR,a[i].s+m-r,a[i].s+m)+(n<<1))%n;
		else
			id[i]=(i+vR+count(pL,a[i].s,a[i].s+r))%n;
	}
	for(int i=0;i<n;++i)
		ans[a[id[i]].old_id]=a[i].f;
	for(int i=0;i<n;++i)
	{
		if(!ans[i])
			ans[i]=m;
		printf("%d%c",ans[i],i+1<n?' ':'\n');
	}
	return 0;
}