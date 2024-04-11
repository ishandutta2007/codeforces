#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

multiset<pair<int,int>> S; 
int n; 
ll ans; 

int main() {
	ans = 0; S.clear(); 
	cin>>n; 
	for (int i = 1; i <= n; ++i) {
		int p; 
		scanf( "%d", &p ); 
		if (S.empty()) {
			S.insert( {p,p} ); 
			continue; 
		}
		auto r = *S.begin(); 
		if (r.fir < p) {
			ans += p-r.fir; 
			S.erase(S.begin()); 
			S.insert({p, r.sec}); 
			if (r.fir != r.sec) S.insert({r.fir, r.fir}); 
		}
		else S.insert( {p,p} ); 
		//cout<<r.fir<<' '<<r.sec<<endl; 
	}
	cout<<ans<<endl; 
}