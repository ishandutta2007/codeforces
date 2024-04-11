#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int m1=998244353;
const int m2=1e9+7;
const int m3=1e9+9;
struct hsh
{
	int a,b,c;
	hsh(ll x=0):a(x%m1),b(x%m2),c(x%m3){}
	hsh(int x, int y, int z):a(x),b(y),c(z){}
	hsh operator + (hsh _b){ return hsh((a+_b.a)%m1,(b+_b.b)%m2,(c+_b.c)%m3);}
	hsh operator - (hsh _b){ return hsh((a-_b.a+m1)%m1,(b-_b.b+m2)%m2,(c-_b.c+m3)%m3);}
	hsh operator * (hsh _b){ return hsh((ll)a*_b.a%m1,(ll)b*_b.b%m2,(ll)c*_b.c%m3);}
	bool operator == (hsh _b){ return a==_b.a && b==_b.b && c==_b.c;}
};
int ls[N],rs[N],tsz,root,y[N],sz[N],val[N];
hsh h[N],po[N],base,one[N];
int MakeNode(int x, int id)
{
	tsz++;
	y[tsz]=(rand()<<12)+rand();
	one[tsz]=h[tsz]=hsh(x);
	sz[tsz]=1;
	val[tsz]=id;
	return tsz;
}
void pull(int c)
{
	if(!c) return;
	sz[c]=sz[ls[c]]+sz[rs[c]]+1;
	h[c]=h[ls[c]]+one[c]*po[sz[ls[c]]]+h[rs[c]]*po[sz[ls[c]]+1];
}
void RotL(int &c)
{
	int a=rs[c],b=ls[a];
	rs[c]=b;ls[a]=c;
	pull(c);pull(a);
	c=a;
}
void RotR(int &c)
{
	int a=ls[c],b=rs[a];
	ls[c]=b;rs[a]=c;
	pull(c);pull(a);
	c=a;
}
void Add(int &c, int x, int id)
{
    if(!c){ c=MakeNode(x,id);return;}
    if(val[c]<id)
	{
		Add(rs[c],x,id);
		if(y[rs[c]]>y[c]) RotL(c);
		else pull(c);
	}
	else
	{
		Add(ls[c],x,id);
		if(y[ls[c]]>y[c]) RotR(c);
		else pull(c);
	}
}
void Del(int &c, int id)
{
	if(!c) return;
	if(val[c]==id)
	{
		if(!ls[c]) c=rs[c];
		else if(!rs[c]) c=ls[c];
		else if(y[ls[c]]>y[rs[c]]) RotR(c),Del(rs[c],id),pull(c);
		else RotL(c),Del(ls[c],id),pull(c);
	}
	else if(val[c]<id) Del(rs[c],id),pull(c);
	else Del(ls[c],id),pull(c);
}
int a[N],b[N],id[N];
int main()
{
	srand(time(0));
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	base=hsh(1000003);
	po[0]=hsh(1);
	for(i=1;i<N;i++) po[i]=po[i-1]*base;
	hsh add(0);
	for(i=0;i<n;i++) add=add+po[i];
	hsh tmp(0);
    for(i=1;i<=n;i++) scanf("%i",&a[i]),tmp=tmp+hsh(a[i])*po[i-1];
    for(i=1;i<=m;i++) scanf("%i",&b[i]),id[i]=i;
    sort(id+1,id+1+m,[&](int i, int j){ return b[i]<b[j];});
    for(j=1;j<n;j++) Add(root,j,id[j]);
    int ans=0;
    for(j=n;j<=m;j++)
	{
		Add(root,j,id[j]);
		//printf("%i %i\n",h[root].a,tmp.a);
		if(h[root]==tmp) ans++;
		tmp=tmp+add;
		Del(root,id[j-n+1]);
	}
	printf("%i\n",ans);
	return 0;
}