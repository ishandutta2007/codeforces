#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
const int M=2*N;
const int H=1000050;
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int inv(int x){ return pow(x,mod-2);}
int x[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int mul)
{
	if(!c) c=++tsz,x[c]=1;
	x[c]=(ll)x[c]*mul%mod;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,mul);
	else Set(rs[c],mid+1,se,qi,mul);
}
int Get(int &c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return 1;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return (ll)Get(ls[c],ss,mid,qs,qe)*Get(rs[c],mid+1,se,qs,qe)%mod;
}
int a[N],last[H],l[N],r[N],sol[N];
bool comp(int i, int j){ return r[i]<r[j];}
vector<int> id[N];
int main()
{
	x[0]=1;
	int n,i,q,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Set(root,1,N,i,a[i]);
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i %i",&l[i],&r[i]),id[r[i]].pb(i);
	for(i=1;i<=n;i++)
	{
		int x=a[i];
		for(j=2;j*j<=x;j++)
		{
			if(x%j) continue;
			if(last[j]) Set(root,1,N,last[j],(ll)j*inv(j-1)%mod);
			Set(root,1,N,i,(ll)(j-1)*inv(j)%mod);
			last[j]=i;
			while(x%j==0) x/=j;
		}
		if(x>1)
		{
			if(last[x]) Set(root,1,N,last[x],(ll)x*inv(x-1)%mod);
			Set(root,1,N,i,(ll)(x-1)*inv(x)%mod);
			last[x]=i;
		}
		for(j=0;j<id[i].size();j++)
		{
			sol[id[i][j]]=Get(root,1,N,l[id[i][j]],r[id[i][j]]);
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}