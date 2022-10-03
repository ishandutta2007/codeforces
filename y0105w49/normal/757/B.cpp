#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define fi first
#define se second
#define pb push_back

const int N=100<<10;

int _main() {
	vector<int> ps;
	static bool isp[N];
	for(int p=2;p<N;p++) isp[p]=1;
	for(int p=2;p<N;p++) {
		if(!isp[p]) continue;
		ps.pb(p);
		for(int x=p+p;x<N;x+=p) isp[x]=0;
	}

	int n; cin>>n;
	static int s[100<<10];
	for(int i=0;i<n;i++) cin>>s[i];
	int be=1;
	map<int,int> ans;
	for(int i=0;i<n;i++) {
		for(int p:ps) {
			if(p*p>s[i]) break;
			if(s[i]%p) continue;
			++ans[p];
			for(;!(s[i]%p);) s[i]/=p;
		}
		if(s[i]>1) ++ans[s[i]];
	}
	for(const auto &P:ans) be=max(be,P.se);
	return be;
}
int main() {
	cout<<_main()<<endl;
}