#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int ls[N],rs[N],sz[N],val[N],tsz;
map<int,int> root;
void Take(int c){ if(!c) return;sz[c]=sz[ls[c]]+sz[rs[c]]+1;}
void Rotate1(int &c){ int a=ls[c],b=rs[a];ls[c]=b;rs[a]=c;Take(c);Take(a);c=a;}
void Rotate2(int &c){ int a=rs[c],b=ls[a];rs[c]=b;ls[a]=c;Take(c);Take(a);c=a;}
void Insert(int &c, int qi)
{
	if(!c){ c=++tsz,val[c]=qi,sz[c]=1;return;}
	if(qi<=val[c]) Insert(ls[c],qi),Rotate1(c);
	else Insert(rs[c],qi),Rotate2(c);
}
int Get(int &c, int qi)
{
	if(!c) return 0;
	int ans;
	if(val[c]<=qi)
	{
		ans=sz[ls[c]]+1+Get(rs[c],qi);
		if(rs[c]) Rotate2(c);
	}
	else
	{
		ans=Get(ls[c],qi);
		if(ls[c]) Rotate1(c);
	}
	return ans;
}
int Get(int &c, int l, int r){ return Get(c,r)-Get(c,l-1);}
int x[N],r[N],f[N],id[N];
bool comp(int i, int j){ return r[i]>r[j];}
int main()
{
	int n,i,j,k,l;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i %i %i",&x[i],&r[i],&f[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	ll sol=0;
	for(j=1;j<=n;j++)
	{
		i=id[j];
		for(l=f[i]-k;l<=f[i]+k;l++) sol+=Get(root[l],x[i]-r[i],x[i]+r[i]);
		Insert(root[f[i]],x[i]);
	}
	printf("%lld\n",sol);
	return 0;
}