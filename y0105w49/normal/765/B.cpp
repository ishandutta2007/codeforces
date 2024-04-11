#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<int> pt;
const int inf=1e9+99;
#define fi first
#define se second

int main() {
	string s; cin>>s;
	char next='a';
	for(char c:s) {
		if(c<next) continue;
		if(c==next) ++next;
		else {
			return cout<<"NO\n",0;
		}
	}
	cout<<"YES\n";
}