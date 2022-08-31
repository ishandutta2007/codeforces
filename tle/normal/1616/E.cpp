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
int q,n; ll ps[SZ];
char s[SZ],t[SZ];
vector<int> v[SZ];
int pc[SZ];
int bs[SZ];
void edt(int x,int y) {
	for(;x<=n;x+=x&-x) bs[x]+=y;
}
int gs(int x) {
	int s=0;
	for(;x>=1;x-=x&-x) s+=bs[x];
	return s;
}
int rp(int x) {
	return gs(n)-gs(x)+x;
}
ll swp(int s,int t,int o) {
	int ans=max(rp(s)-t,0);
	if(o) edt(s,1);
	return ans;
}
void sol() {
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;++i) bs[i]=0;
	for(int i='a';i<='z';++i)
		v[i].clear(),pc[i]=0;
	for(int i=1;i<=n;++i) v[s[i]].pb(i);
	ll ans=2e18,ca=0;
	for(int i=1;i<=n;++i) {
		for(int z='a';z<t[i];++z) {
			if(pc[z]<v[z].size())
				ans=min(ans,ca+swp(v[z][pc[z]],i,0));
		}
//		cout<<i<<":"<<ans<<","<<ca<<",";
		int t=::t[i];
//		cout<<t<<"("<<pc[t]<<","<<v[t].size()<<")\n";
		if(pc[t]<v[t].size()) {
			ca+=swp(v[t][pc[t]++],i,1);
		}
//			ca+=max(v[t][pc[t]++]-i,0);
		else ca=2e18;
//		cout<<ca<<"\n";
	}
	if(ans>1e18) ans=-1;
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&q);
	while(q--) sol();
}