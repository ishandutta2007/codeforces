#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
int n,qz[2333333],r[2333333];
bool f[2333333];
char s[2333333];
bool ok(int g)
{
	for(int i=0;i<=n;++i) r[i]=qz[i]=f[i]=0;
	f[0]=qz[0]=1;
	int lp=-1;
	for(int i=1;i<=n;++i)
	{
		r[i]+=r[i-1]; f[i]=r[i];
		if(s[i]!='*') f[i]|=f[i-1];
		if(s[i]=='P')
		{
			if(f[i])
				++r[i+1],--r[min(i+g,n)+1];
			int l=max(i-g,0);
			//cout<<i<<"bt"<<l<<"!!\n";
			int s=qz[i-1];
			if(l>=2) s-=qz[l-2];
			int b=lp; lp=i;
			if(s||f[i])
			{
			f[i]=1;
			if(b!=-1&&b>=i-g&&qz[b-1]-((l>=2)?qz[l-2]:0))
				++r[i+1],--r[min(b+g,n)+1];
			}
		}
		qz[i]=qz[i-1]+f[i];
	}
	//for(int i=0;i<=n;++i) cout<<f[i];
	//cout<<"\n";
	return f[n];
}
int main()
{
	scanf("%d%s",&n,s+1);
	int c=0,x,p=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='P') ++c,x=i;
		else if(s[i]=='*') ++p;
	if(c==1)
	{
		pii ans(-1e9,1e9);
		int cnt=0,tt=0;
		for(int i=x,j=0;i>=1;--i,--j)
			if(s[i]=='*') ++cnt,tt=j;
		ans=max(ans,pii(cnt,tt));
		cnt=tt=0;
		for(int i=x,j=0;i<=n;++i,--j)
			if(s[i]=='*') ++cnt,tt=j;
		ans=max(ans,pii(cnt,tt));
		printf("%d %d\n",ans.fi,-ans.se);
		return 0;
	}
	/*
	cout<<ok(4)<<"\n";
	system("pause");
	cout<<ok(3)<<"\n";
	system("pause");
	cout<<ok(2)<<"\n";
	system("pause");*/
	int l=0,r=n;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(ok(m)) r=m; else l=m+1;
	}
	printf("%d %d\n",p,l);
}