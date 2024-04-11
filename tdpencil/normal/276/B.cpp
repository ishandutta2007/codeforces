#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;
// #define runcase LOL

void solve(int test_case = 0)
{
    // brute force all good digits
	string s; cin >> s;
	vector<int> cnt(26);
	for(char ch : s) {
		cnt[ch - 'a']++;
	}
	int res =0;
	for(int i : cnt) {
		if(i%2==1) res++;
	}
	res=max(0, res-1);
	if(res%2==0) {
		cout << "First";
	} else {
		cout << "Second";
	}
	
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}