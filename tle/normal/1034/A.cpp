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
#define S 15000009
int n,a[SZ],cn[S];
bool np[S];
int main()
{
	scanf("%d",&n); int g=0;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),g=__gcd(g,a[i]);
	for(int i=1;i<=n;++i) ++cn[a[i]/g];
	int mx=0;
	for(int i=2;i<S;++i) if(!np[i])
	{
		int cs=0;
		for(int j=i;j<S;j+=i)
			cs+=cn[j], np[j]=1;
		mx=max(mx,cs);
	}
	if(mx==0) mx=n+1;
	printf("%d\n",n-mx);
}