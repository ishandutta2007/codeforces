#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, x;
vector<int> tofit, toerase;
set<int> nogo;
void solve() {
	cin >> n;
	for(int i=1;i<=n;i++)
		nogo.insert(i);
    int a=0;
	for(int i=0;i<n;i++) {
		cin >> x;
		if(nogo.count(x)) nogo.erase(x);
		else tofit.push_back(x), a++;
	}
	
    sort(tofit.rbegin(), tofit.rend());
    for(int i : nogo) {
        if(tofit.back()>i*2) {
            toerase.push_back(i); 
        }
        tofit.pop_back();
    }
    for(int i : toerase) nogo.erase(i);

    cout << (nogo.empty()?a:-1) << "\n";
    nogo.clear();
    tofit.clear();
    toerase.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	 cin >> T;
	while(T--) {
        solve();
	}
}