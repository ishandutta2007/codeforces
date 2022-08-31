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
int T,n; ll a[SZ],x,f[SZ];
bool good(int l,int r) {
	for(int i=l;i<=r;++i) {
		ll s=0;
		for(int j=i;j<=r;++j) {
			s+=a[j];
			if(j>i&&s<0) return 0;
		}
	}
	return 1;
}
void sol() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	scanf("%lld",&x);
	for(int i=1;i<=n;++i) a[i]-=x;
	f[0]=0;
	for(int i=1;i<=n;++i) {
		ll aa=f[i-1];
		for(int j=1;j<=i&&j<=8;++j) {
			if(good(i-j+1,i)) {
				aa=max(aa,f[max(i-j-1,0)]+j);
				if(i-j-2>=1&&i-j+2<=i&&good(i-j-2,i-j+2)) {
					aa=max(aa,f[i-j]+j);
				}
			}
		}
		f[i]=aa;
	}
	printf("%lld\n",f[n]);
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}