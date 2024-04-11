#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
const int N=300050;
const int M=2*N;
int root,tsz,ls[M],rs[M],sz[M],y[M];
ll sum[M],val[M];
int MakeNode(int f)
{
	tsz++;
	sz[tsz]=1;
	y[tsz]=(rand()<<12)+rand();
	sum[tsz]=val[tsz]=f;
	return tsz;
}
void pull(int c)
{
	if(!c) return;
	sz[c]=sz[ls[c]]+sz[rs[c]]+1;
	sum[c]=sum[ls[c]]+val[c]+sum[rs[c]];
}
void RotL(int &c)
{
	int a=rs[c],b=ls[a];
	rs[c]=b;ls[a]=c;
	pull(c);pull(a);c=a;
}
void RotR(int &c)
{
	int a=ls[c],b=rs[a];
	ls[c]=b;rs[a]=c;
	pull(c);pull(a);c=a;
}
void Add(int &c, int f)
{
	if(!c){ c=MakeNode(f);return;}
	if(val[c]<f)
	{
		Add(rs[c],f);
		if(y[rs[c]]>y[c]) RotL(c);
		else pull(c);
	}
	else
	{
		Add(ls[c],f);
		if(y[ls[c]]>y[c]) RotR(c);
		else pull(c);
	}
}
void Del(int &c, int f)
{
	if(!c) return;
	if(val[c]<f) Del(rs[c],f),pull(c);
	else if(val[c]>f) Del(ls[c],f),pull(c);
	else
	{
		if(!ls[c]) c=rs[c];
		else if(!rs[c]) c=ls[c];
		else if(y[ls[c]]>y[rs[c]]) RotR(c),Del(rs[c],f),pull(c);
		else RotL(c),Del(ls[c],f),pull(c);
	}
}
ll Get(int c, int k)
{
	if(!c) return 0;
    if(sz[ls[c]]+1<=k) return sum[ls[c]]+val[c]+Get(rs[c],k-sz[ls[c]]-1);
    else return Get(ls[c],k);
}
int a[N],b[N],id[N],d[N],c[N],ret[N];
int main()
{
	srand(time(0));
	int n,i,w;
	scanf("%i %i",&n,&w);
	for(i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]),id[i]=i;
	sort(id+1,id+1+n,[&](int i, int j){ return mp(b[i],a[i])<mp(b[j],a[j]);});
	for(i=1;i<=n;i++) Add(root,a[i]);
	ll sum=0,ans=9e18;
	int sol=-1;
	if(w<=n) ans=Get(root,w),sol=0;
    for(i=1;i<=n;i++)
	{
		sum+=a[id[i]];
		Del(root,a[id[i]]);
		Add(root,b[id[i]]-a[id[i]]);
		if(i+n>=w)
		{
			ll tmp=sum+Get(root,w-i);
			if(ans>tmp) ans=tmp,sol=i;
		}
	}
	printf("%lld\n",ans);
	for(i=1;i<=sol;i++) d[id[i]]=b[id[i]]-a[id[i]];
	for(i=sol+1;i<=n;i++) d[id[i]]=a[id[i]];
	for(i=1;i<=n;i++) c[i]=i;
	sort(c+1,c+1+n,[&](int i, int j){ return d[i]<d[j];});
	for(i=1;i<=w-sol;i++) ret[c[i]]++;
	for(i=1;i<=sol;i++) ret[id[i]]++;
	for(i=1;i<=n;i++) printf("%i",ret[i]);
	return 0;
}