#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



void solve() {
	string s, t;
	cin >> s >> t;
	
	vi a(26), b(26);
	for(char ch : s) ++a[ch - 'a'];
	for(char ch : t) ++b[ch - 'a'];
	bool allgreat=true,allgood=true,issubsequence=true;
	int ptr=0;
	for(char ch : s) if(ptr < sz(t) && t[ptr] == ch) ++ptr;
	issubsequence&=ptr==sz(t);
	rep(i,0,26) {
		allgreat&=a[i]>=b[i];
		allgood&=a[i]==b[i];
	}
	if(allgood) {
		cout << "array";
	} else if(allgreat&&issubsequence) {
		cout << "automaton";
	} else if(allgreat) {
		cout << "both";
	} else {
		cout << "need tree";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
//	cin >> t;
    while(t--) {
        solve();
    }
}