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
int T,n,m,k,u[26];
char s[SZ];
bool b[SZ],x[SZ];
void sol()
{
	scanf("%d%d%d%s",&n,&m,&k,s);
	memset(u,0,sizeof u);
	for(int i=0;s[i];++i) ++u[s[i]-'A'];
	for(int j=0;j<=k;++j) b[j]=0; b[0]=1;
	for(int i=0;i<26;++i)
		for(int j=k;j>=u[i];--j)
			b[j]|=b[j-u[i]];
	for(int i=n;i<=k-m;++i)
		if(b[i])
		{
			puts("0");
			return;
		}
	for(int j=0;j<=k;++j) b[j]=0; b[0]=1;
	ll ans=8e18;
	for(int i=0;i<26;++i)
	{
		for(int j=0;j<=k;++j) x[j]=b[j];
		for(int j=i+1;j<26;++j)
			for(int t=k;t>=u[j];--t)
				x[t]|=x[t-u[j]];
		int t=k-u[i];
		for(int j=0;j<=t;++j) if(x[j])
		{
			int a=max(n-j,0),b=max(m-(t-j),0);
			if(a+b<=u[i]) ans=min(ans,(ll)a*b);
		}
		for(int t=k;t>=u[i];--t)
			b[t]|=b[t-u[i]];
	}
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}