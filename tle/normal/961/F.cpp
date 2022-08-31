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
#define SZ 1234567
char s[SZ]; int n,ct[SZ];
const int MOD=998244353;
ll p[2]={1234567,2333333};
ll qz[2][SZ],po[2][SZ];
ll hsh(int l,int r) {
	int h0=(qz[0][r]-qz[0][l-1]*po[0][r-l+1])%MOD;
	int h1=(qz[1][r]-qz[1][l-1]*po[1][r-l+1])%MOD;
	if(h0<0) h0+=MOD; if(h1<0) h1+=MOD;
//	cerr<<l<<","<<r<<":"<<h0<<","<<h1<<"\n";
	return h0*(ll)MOD+h1;
}
int main()
{
	scanf("%*d");
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int o=0;o<2;++o) {
		po[o][0]=1;
		for(int i=1;i<=n;++i)
			qz[o][i]=(qz[o][i-1]*p[o]+s[i])%MOD,
			po[o][i]=po[o][i-1]*p[o]%MOD;
	}
	for(int i=1;i<=n/2;++i) {
		int l=-1,r=i-1;
		while(l<r) {
			int m=l+(r-l+1)/2;
			if(hsh(i-m,i+m)==hsh(n+1-i-m,n+1-i+m))
				l=m;
			else r=m-1;
		}
		ct[i-l]=max(ct[i-l],i);
	}
	for(int i=1;i<=(n+1)/2;++i) {
		ct[i]=max(ct[i],ct[i-1]);
		int ans=max(ct[i]-i,-1)*2+1;
		printf("%d ",ans);
	}
}