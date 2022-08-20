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
#define N 233333
int T,n;
char ch[N<<1];
int f[N<<1];
//f[i*2]: i centered; f[i*2+1]: (i,i+1) centered
void manacher(char *s) {
	int n=strlen(s),id=0,mx=0;
	ch[0]='$'; ch[1]='#';
	for(int i=1;i<=n;i++)
		ch[i*2]=s[i-1], ch[i*2+1]='#';
	ch[n*2+2]='#';
	for(int i=0;i<=2*n+10;i++) f[i]=0;
	for(int i=1;i<=2*n+2;i++) {
		if(i>mx) f[i]=1; else f[i]=min(f[id*2-i],mx-i);
		while(ch[i-f[i]]==ch[i+f[i]]) f[i]++;
		if(i+f[i]>mx) {mx=i+f[i]; id=i;}
	}
}
char s[N];
void sol() {
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<n;++i) {
		if(s[i]<s[i+1]) {
			n=i; break;
		}
	}
	bool ae=1;
	for(int i=1;i<=n;++i)
		ae&=s[i]==s[1];
	if(s[1]==s[2]) n=1;
	if(ae) n=1;
	for(int i=1;i<=n;++i) putchar(s[i]);
	for(int i=n;i;--i) putchar(s[i]);puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}