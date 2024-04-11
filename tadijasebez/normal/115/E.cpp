#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int M=2*N;
const ll inf=9e18;
vector<int> ids[N];
int a[N],l[N],r[N],p[N];
ll dp[N];
int ls[M],rs[M],tsz,root;
ll mx[M],lzy[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;mx[c]=lzy[c]=0;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Push(int c, int ss, int se)
{
    if(!lzy[c]) return;
    if(ss!=se)
	{
		mx[ls[c]]+=lzy[c];lzy[ls[c]]+=lzy[c];
		mx[rs[c]]+=lzy[c];lzy[rs[c]]+=lzy[c];
	}
	lzy[c]=0;
}
void Inc(int c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>se || ss>qe || qs>qe) return;
	if(qs<=ss && qe>=se){ mx[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Push(c,ss,se);
	Inc(ls[c],ss,mid,qs,qe,f);
	Inc(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return -inf;
	if(qs<=ss && qe>=se) return mx[c];
	Push(c,ss,se);
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++) scanf("%i %i %i",&l[i],&r[i],&p[i]),ids[r[i]].pb(i);
	Build(root,1,n);
	for(i=1;i<=n;i++)
	{
        Inc(root,1,n,1,i,-a[i]);
        Inc(root,1,n,i,i,dp[i-1]);
        for(int j:ids[i]) Inc(root,1,n,1,l[j],p[j]);
		dp[i]=max(Get(root,1,n,1,i),dp[i-1]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}