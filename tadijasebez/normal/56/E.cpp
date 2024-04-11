#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
const int N=100050;
const int M=32*N;
const int inf=3e8;
int rmq[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz,rmq[c]=-inf;
	rmq[c]=max(rmq[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	//if(c==root) printf("->%i %i<-\n",qs,qe);
	if(ss>qe || qs>se) return -inf;
	if(qs<=ss && qe>=se) return rmq[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int h[N],x[N],id[N],rng[N];
bool comp(int a, int b){ return x[a]<x[b];}
vector<int> Xs;
int main()
{
	rmq[0]=-inf;
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&x[i],&h[i]),id[i]=i,Xs.pb(x[i]);
	sort(id+1,id+1+n,comp);
	sort(Xs.begin(),Xs.end());
	for(i=n;i;i--)
	{
		rng[id[i]]=Get(root,-inf,inf,x[id[i]],x[id[i]]+h[id[i]]-1);
		//printf("(%i %i)\n",id[i],rng[id[i]]);
		rng[id[i]]=max(rng[id[i]],x[id[i]]+h[id[i]]-1);
		Set(root,-inf,inf,x[id[i]],rng[id[i]]);
	}
	//for(i=1;i<=n;i++) printf("%i ",rng[i]);printf("\n");
	for(i=1;i<=n;i++)
	{
		int l=lower_bound(Xs.begin(),Xs.end(),x[i])-Xs.begin();
		int r=upper_bound(Xs.begin(),Xs.end(),rng[i])-Xs.begin()-1;
		printf("%i ",r-l+1);
	}
	printf("\n");
	return 0;
}