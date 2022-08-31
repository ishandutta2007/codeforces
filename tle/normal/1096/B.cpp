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
char s[SZ];
int cn[SZ],n;
bool chk(int l,int r)
{
	if(l==1&&r==n) return 1;
	int p;
	if(l!=1) p=s[l-1];
	else p=s[r+1];
	return cn[p]==n-(r-l+1);
}
int main()
{
	scanf("%d%s",&n,s+1);
	ll ans=0;
	for(int i=1;i<=n;++i) ++cn[s[i]];
	for(int i=1,j=i-1;i<=n;++i)
	{
		if(i>1) ++cn[s[i-1]];
		while(j<i||(j<=n&&!chk(i,j))) --cn[s[++j]];
		ans+=n-j+1; ans%=998244353;
	}
	cout<<ans<<"\n";
}