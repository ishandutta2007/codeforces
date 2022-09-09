#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
const int M=2*N;
vector<pair<ll,int> > x[M];
int ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, ll val)
{
	if(!c) c=++tsz;
	if(ss==se)
	{
		x[c].clear();
		if(~val) x[c].pb(mp(val,qi));
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	x[c].clear();
	int i;
	for(i=0;i<x[ls[c]].size();i++) x[c].pb(x[ls[c]][i]);
	for(i=0;i<x[rs[c]].size();i++) x[c].pb(x[rs[c]][i]);
	sort(x[c].begin(),x[c].end());
	while(x[c].size()>3) x[c].pop_back();
}
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	if(!(n&1)) n++;
	for(i=1;i<=n;i++) Set(root,1,n,i,a[i]);
	ll sol=0;
	while(x[root].size()>1)
	{
		vector<pair<ll,int> > tmp;
		for(i=0;i<x[root].size();i++) tmp.pb(x[root][i]);
		ll sum=0;
		for(i=0;i<tmp.size();i++)
		{
			sum+=tmp[i].first;
			Set(root,1,n,tmp[i].second,-1);
		}
		sol+=sum;
		Set(root,1,n,tmp[0].second,sum);
	}
	printf("%lld\n",sol);
	return 0;
}