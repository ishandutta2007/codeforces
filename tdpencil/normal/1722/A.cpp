#include <bits/stdc++.h>
using namespace std;
void run_case() {
    string t="Timur";
    sort(t.begin(),t.end());
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    
    cout << (s==t?"YES":"NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
		run_case();
	}
}