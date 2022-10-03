// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;





typedef ll BS;
void SEP(ll &x,int i,bool b) {
	x |= ll(b)<<i;
}

vector<BS> bss[220][128];
string pref[220],suff[220];
void nz(int i) {
	for(int l=1;l<=40;l++) {
		vector<BS> &v=bss[i][l];
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
	}
	pref[i]=pref[i].substr(0,40);
	suff[i]=suff[i].substr(max(0,(int)suff[i].size()-40));
}



int32_t main() {
	int n; cin>>n;
	for(int i=1;i<=n;i++) {
		string s; cin>>s;
		pref[i]=suff[i]=s;
		for(int L=0;L<(int)s.size();L++) for(int R=L;R<(int)s.size();R++) {
			BS bs=0;
			for(int j=L;j<=R;j++) SEP(bs,j-L,s[j]=='1');
			bss[i][R-L+1].pb(bs);
		}
		nz(i);
	}

	int m; cin>>m;
	for(int i=n+1;i<=n+m;i++) {
		int a,b; cin>>a>>b;
		for(int l=1;l<=40;l++) {
			for(auto x:bss[a][l]) bss[i][l].pb(x);
			for(auto x:bss[b][l]) bss[i][l].pb(x);
		}
		for(int L=0;L<(int)suff[a].size();L++) for(int R=0;R<(int)pref[b].size();R++) {
			string s=suff[a].substr(L)+pref[b].substr(0,R+1);
			if(s.size()>40u) continue;
			BS bs=0;
			for(int j=0;j<(int)s.size();j++) SEP(bs,j,s[j]=='1');
			bss[i][(int)s.size()].pb(bs);
		}

		pref[i]=pref[a]+pref[b];
		suff[i]=suff[a]+suff[b];
		nz(i);

		int k=35;
		for(;;) {
			if(!k) break;
			if((ll)bss[i][k].size() == (1LL<<k)) break;
			--k;
		}
		cout<<k<<endl;
	}
}