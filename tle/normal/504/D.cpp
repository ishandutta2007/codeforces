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
#include <assert.h>
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
int m;
ll u[706];
char s[706];
#define S 700
#define U 2010
bitset<4050> b,g[U];
bool hg[U];
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
//		s[0]='1';
//		for(int j=1;j<=600;++j)
//			s[j]='0';
		scanf("%s",s);
		memset(u,0,sizeof u);
		int l=strlen(s);
		for(int i=l-1;~i;--i)
			u[i/18]=u[i/18]*10+s[l-1-i]-48;
		vector<int> vv;
		int r=S-1;
		while(1)
		{
			while(r>=0&&!u[r]) --r;
			if(r<0) break;
			vv.pb(u[0]&1); u[0]&=~1;
			for(int i=r;i>=0;--i)
				u[i-1]+=1000000000000000000LL*(u[i]&1), //ub
				u[i]>>=1;
		}
		bitset<4050> o;
		o.reset();
		for(int i=0;i<vv.size();++i)
			o[i]=vv[i];
		o[i+U]=1;
		bool put=0;
		for(int i=0;i<U;++i) if(o[i])
		{
			if(hg[i]) {o^=g[i]; continue;}
			//put it here
			for(int j=i-1;j>=0;--j)
				if(hg[j]&&o[j]) o^=g[j];
			hg[i]=1; g[i]=o;
			for(int j=i+1;j<U;++j)
				if(hg[j]&&g[j][i]) g[j]^=o;
			put=1; break;
		}
		if(!put)
		{
			vector<int> v;
			for(int j=1;j<i;++j)
				if(o[j+U]) v.pb(j);
			printf("%d",int(v.size()));
			for(auto x:v) printf(" %d",x-1);
			puts("");
		}
		else
		{
			puts("0");
		}
	}
}