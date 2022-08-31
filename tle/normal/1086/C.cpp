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
#define SZ 1234567
int T,k,l;
char s_[SZ],a_[SZ],b_[SZ],ys[129],fy[129],
yt[129],ft[129],*a=a_,*b=b_,*s=s_;
#define NO {puts("NO");return;}
#define cango can_go
bool can_go(char a,char b)
{
	if(ys[a]!=-1&&ys[a]!=b) return 0;
	if(fy[b]!=-1&&fy[b]!=a) return 0;
	return 1;
}
void sett(char a,char b)
{
	ys[a]=b; fy[b]=a;
}
void fix_empty_and_op()
{
	static int as[233];
	int an=0;
	for(int i=0;i<k;++i)
		if(fy[i+'a']==-1) as[an++]=i+'a';
	an=0;
	for(int i=0;i<k;++i)
		if(ys[i+'a']==-1) ys[i+'a']=as[an++];
	puts("YES");
	for(int i=0;i<k;++i)
		putchar(ys[i+'a']);
	puts("");
	return;
}
void sol()
{
	a=a_,b=b_,s=s_;
	scanf("%d%s%s%s",&k,s,a,b);
	for(int i=0;i<k;++i)
		ys[i+'a']=fy[i+'a']=-1;
	l=strlen(a);
	while(l&&a[0]==b[0])
	{
		if(!can_go(s[0],a[0])) NO
		sett(s[0],a[0]); ++a; ++b; ++s; --l;
	}
	if(!l)
	{
		fix_empty_and_op(); return;
	}
	for(int x=a[0]+1;x<b[0];++x)
		if(can_go(s[0],x))
		{
			sett(s[0],x);
			fix_empty_and_op(); return;
		}
	//try two shit
	for(int i=0;i<k;++i)
		yt[i+'a']=ys[i+'a'],
		ft[i+'a']=fy[i+'a'];
	if(can_go(s[0],a[0]))
	{
		sett(s[0],a[0]);
		for(int t=1;t<l;++t)
		{
			for(int x=a[t]+1;x<k+'a';++x)
			{
				if(cango(s[t],x))
				{
					sett(s[t],x);
					fix_empty_and_op(); return;
				}
			}
			if(!cango(s[t],a[t])) goto next_shit;
			sett(s[t],a[t]);
		}
		fix_empty_and_op(); return;
	}
	next_shit:
	for(int i=0;i<k;++i)
		ys[i+'a']=yt[i+'a'],
		fy[i+'a']=ft[i+'a'];
	if(can_go(s[0],b[0]))
	{
		sett(s[0],b[0]);
		for(int t=1;t<l;++t)
		{
			for(int x=b[t]-1;x>='a';--x)
			{
				if(cango(s[t],x))
				{
					sett(s[t],x);
					fix_empty_and_op(); return;
				}
			}
			if(!cango(s[t],b[t])) NO
			sett(s[t],b[t]);
		}
		fix_empty_and_op(); return;
	}
	NO
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}