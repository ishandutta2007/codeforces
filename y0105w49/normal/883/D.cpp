// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;




const int N=1<<20;
int n;
char s[N];

int need[N],ps[N],prv[N];

int go(int ac) {
	int L=0,R=n;
	for(int i=1;i<=n;i++) if(s[i]=='*') ps[i]=1;
	for(int i=1;i<=n;i++) prv[i]=(s[i]=='P' ? i : prv[i-1]);
	partial_sum(ps+1,ps+1+n,ps+1);
	for(;L!=R;) {
		int bes=0;
		for(int i=0;i<=ac;i++) need[i]=inf;
		need[0]=0;
		int M=(L+R)/2;
		for(int i=1;i<=n;i++) {
			if(s[i]!='P') continue;
			int a=ps[i];
			int cur;
			if(need[a]!=inf) {
				cur=i+M;
			} else {
				// go left
				int j=prv[i-1]; // we want to shoot this right
				int k=need[ps[max(i-M-1,0)]];
				if(k==inf) goto die;
				if(k<j) cur=max(j+M,i);
				else cur=i;
			}
			cur=ps[min(cur,n)];
			assert(cur>=bes);
			for(;cur>bes;) need[++bes]=i;
		}
		above:;
		if(need[ac]!=inf) R=M;
		else L=M+1;
		continue;
		die:;
		need[ac]=inf;
		goto above;
	}
	return L;
}



int32_t main() {
	scanf("%d%s",&n,s+1);
	int pc=0;
	for(int i=1;i<=n;i++) if(s[i]=='P') ++pc;
	assert(pc>=1);
	if(pc==1) {
		int pi=-1;
		for(int i=1;i<=n;i++) if(s[i]=='P') pi=i;
		assert(~pi);
		int lc=0,rc=0;
		int li=-1,ri=-1;
		for(int i=pi;--i>=1;) if(s[i]=='*') ++lc, li=i;
		for(int i=pi;++i<=n;) if(s[i]=='*') ++rc, ri=i;
		assert(lc || rc);
		if(lc==rc) return printf("%d %d\n",lc,min(pi-li,ri-pi)),0;
		int t=lc>rc?pi-li:ri-pi;
		return printf("%d %d\n",max(lc,rc),t),0;
	}

	int ac=0;
	for(int i=1;i<=n;i++) if(s[i]=='*') ++ac;
	assert(ac>0);
	printf("%d %d\n",ac,go(ac));
}