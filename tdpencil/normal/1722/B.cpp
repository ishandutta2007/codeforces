#include <bits/stdc++.h>
using namespace std;
void run_case() {
	int n;
	cin >> n;
    string a, b;
    cin >> a >> b;
    bool g=1;
    for (int i=0;i<n;i++) {
    	int fv=(a[i]=='R'?1:0),sv=(b[i]=='R'?1:0);
    	g&=fv==sv;
	}
	cout << (g?"YES":"NO") << "\n";
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