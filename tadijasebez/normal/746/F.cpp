#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int M=2*N;
vector<pair<int,int> > id;
int Find(pair<int,int> x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int ls[M],rs[M],sz[M],tsz,root;
ll sum[M],hal[M];
void Add(int &c, int ss, int se, int qi, ll val, int f)
{
	if(!c) c=++tsz;
	sz[c]+=f;sum[c]+=val*f;hal[c]+=(val+1>>1)*f;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Add(ls[c],ss,mid,qi,val,f);
	else Add(rs[c],mid+1,se,qi,val,f);
}
ll Get(int c, int ss, int se, int k)
{
	if(ss==se) return k>0?hal[c]:sum[c];
	int mid=ss+se>>1;
	if(sz[rs[c]]<=k) return hal[rs[c]]+Get(ls[c],ss,mid,k-sz[rs[c]]);
	else return sum[ls[c]]+Get(rs[c],mid+1,se,k);
}
int t[N],a[N];
int main()
{
	int n,k,w,i;
	scanf("%i %i %i",&n,&w,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n;i++) scanf("%i",&t[i]),id.pb(mp(t[i],i));
	sort(id.begin(),id.end());
	int lim=id.size();
	int j=1,sol=0;
	for(i=1;i<=n;i++)
	{
		while(j<=n+1 && Get(root,1,lim,w)<=k) Add(root,1,lim,Find(mp(t[j],j)),t[j],1),j++;
		//printf("i:%i j:%i\n",i,j);
		sol=max(sol,a[j-2]-a[i-1]);
		Add(root,1,lim,Find(mp(t[i],i)),t[i],-1);
	}
	printf("%i\n",sol);
	return 0;
}