#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int S=305;
vector<int> pr;
int go[S];
void FindPrimes()
{
	for(int i=2;i<S;i++) if(!go[i])
	{
		pr.pb(i);
		for(int j=i*2;j<S;j+=i) go[j]=i;
	}
}
const int N=400050;
const int M=2*N;
const int mod=1e9+7;
int mul(int x, int y){ return (ll)x*y%mod;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
int ls[M],rs[M],tsz,root,lzy[M],pro[M],a[N];
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=1;
	if(ss==se){ pro[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	pro[c]=mul(pro[ls[c]],pro[rs[c]]);
}
void mdy(int c, int ss, int se, int x)
{
	lzy[c]=mul(lzy[c],x);
	pro[c]=mul(pro[c],pow(x,se-ss+1));
}
void push(int c, int ss, int se)
{
	if(lzy[c]==1) return;
	int mid=ss+se>>1;
	mdy(ls[c],ss,mid,lzy[c]);
	mdy(rs[c],mid+1,se,lzy[c]);
	lzy[c]=1;
}
void Set(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ mdy(c,ss,se,x);return;}
	int mid=ss+se>>1;
	push(c,ss,se);
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
	pro[c]=mul(pro[ls[c]],pro[rs[c]]);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 1;
	if(qs<=ss && qe>=se) return pro[c];
	int mid=ss+se>>1;
	push(c,ss,se);
	return mul(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
struct BIT
{
	int mx[N];
	BIT(){}
	void Set(int i, int x){ for(;i<N;i+=i&-i) mx[i]=max(mx[i],x);}
	int Get(int i){ int ans=0;for(;i;i-=i&-i) ans=max(ans,mx[i]);return ans;}
} BT[62];
char t[20];
int main()
{
	FindPrimes();
	int n,q,i,j,l,r,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	for(i=1;i<=n;i++) for(j=0;j<pr.size();j++) if(a[i]%pr[j]==0) BT[j].Set(i,i);
	vector<int> ipr;
	for(j=0;j<pr.size();j++) ipr.pb(inv(pr[j]));
	while(q--)
	{
		scanf("%s %i %i",&t,&l,&r);
		if(t[0]=='T')
		{
			int ans=Get(root,1,n,l,r);
			for(j=0;j<pr.size();j++) if(BT[j].Get(r)>=l) ans=mul(ans,mul(ipr[j],pr[j]-1));
			printf("%i\n",ans);
		}
		else
		{
			scanf("%i",&x);
			Set(root,1,n,l,r,x);
			for(j=0;j<pr.size();j++) if(x%pr[j]==0) BT[j].Set(l,r);
		}
	}
	return 0;
}