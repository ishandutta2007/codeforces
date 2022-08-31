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
#define SZ 666666
int T,n,m,x[23333],y[23333],d[23333],ps[23333];
bitset<2005> b[2005];
namespace FF{
char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
int aa,bb;int F(){
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}}
#define gi FF::F()
void sol()
{
    n=gi,m=gi;
	for(int i=1;i<=n;++i)
		d[i]=0,memset(&b[i],0,sizeof b[0]);
	for(int i=1;i<=m;++i)
	    x[i]=gi,y[i]=gi,
		++d[x[i]],++d[y[i]],
		b[x[i]][y[i]]=1,
		b[y[i]][x[i]]=1;
	bool ok=1;
	for(int i=1;i<=n;++i) ok&=d[i]%2==0;
	if(ok)
	{
		puts("1");
		for(int i=1;i<=n;++i) printf("1 ");
		puts(""); return;
	}
	for(int i=1;i<=n;++i)
		if(d[i]&1) b[i][i]=1,b[i][0]=1;
	for(int i=1;i<=n;++i) d[i]=0;
	int c=1;
	for(int i=1;i<=n;++i)
	{
		int j=-1; ps[i]=0;
		for(int t=c;t<=n;++t)
			if(b[t][i]) {j=t; break;}
		if(j==-1) continue;
		swap(b[j],b[c]); ps[i]=c;
		for(int t=1;t<=n;++t)
			if(t!=c&&b[t][i])
				b[t]^=b[c];
		++c;
	}
	for(int i=1;i<=m;++i)
		if(b[ps[x[i]]][0]==b[ps[y[i]]][0])
			++d[x[i]],++d[y[i]];
	for(int i=1;i<=n;++i)
		if(d[i]&1) throw "GG";
	puts("2");
	for(int i=1;i<=n;++i)
		if(b[ps[i]][0]) printf("1 ");
		else printf("2 ");
	puts("");
}
int main()
{
    T=gi;
	while(T--) sol();
}