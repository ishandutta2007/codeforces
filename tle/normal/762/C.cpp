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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
struct Seq_A_M
{
int par[SZ],ch[SZ][26],lst[26],C,rot;
Seq_A_M()
{
    C=rot=1;
    for(int i=0;i<26;i++) lst[i]=rot;
}
void ins(char c)
{
    ++C; par[C]=lst[c];
    for(int i=0;i<26;i++)
    {
        for(int g=lst[i];g&&!ch[g][c];g=par[g]) ch[g][c]=C;
    }
    lst[c]=C;
}
}S1,S2;
char a[SZ],b[SZ];
int qz_[SZ],*qz=qz_+1,hz[SZ];
int main()
{
	scanf("%s%s",a,b);
	int sa=strlen(a);
	for(int i=0;a[i];i++)
		S1.ins(a[i]-'a');
	for(int i=0;a[i];i++)
		S2.ins(a[sa-1-i]-'a');
	int s=1;
	for(int i=0;b[i];i++)
		qz[i]=sa+1, hz[i]=0;
	int sb=strlen(b);
	qz[-1]=0; hz[sb]=sa;
	int mcl=1e9,l,r;
	for(int i=0;b[i];i++)
	{
		int c;
		if(c=S1.ch[s][b[i]-'a']);else break;
		s=c; qz[i]=c-1;
		int cl=i+1,cr=sb-1,lp=cr-cl+1;
		if(lp<mcl) mcl=lp, l=cl, r=cr;
	}
	s=1;
	for(int i=sb-1;i>=0;i--)
	{
		int c;
		if(c=S2.ch[s][b[i]-'a']);else break;
		s=c; hz[i]=sa+2-c;
		int cl=0,cr=i-1,lp=cr-cl+1;
		if(lp<mcl) mcl=lp, l=cl, r=cr;
	}
	int p=0; ll ans=0;
	for(int i=0;b[i];i++)
	{
		while(p<sb&&qz[i]>=hz[p]) ++p;
		if(p<sb)
		{
			int cl=max(p-i-1,0);
			if(cl>mcl) continue;
			mcl=cl; l=i+1; r=p-1;
		}
	}
	if(mcl<sb)
	{
		for(int j=0;j<sb;j++)
		{
			if(l<=j&&j<=r) continue;
			putchar(b[j]);
		}
	}
	else puts("-");
}