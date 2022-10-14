#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k;
vector<int> ans;

void dfs(int l, int p) {
	if(l > n) return;
	if(p) {
		ans.push_back(l);
	} else ++l;
	dfs(l + k, p ^ 1);
}
void solve() {
	cin >> n >> k;
    if(k == 0) {
        cout << n << "\n";
        for(int i = 0; i < n; i++) {
			cout << i +1 << " ";
		}
        return;
    }
    vector<int> better;
    
    for(int i = 1; i <= n; i++) {
        ans.clear();
        vector<bool> vis(n+1);
        dfs(i, 1);
        for(int j : ans) {
            for(int x = j - k; x <= j + k; x++) {
                if(x>0&&x<=n) {
                    vis[x]=1;
                }
            }
        }
        bool dw=1;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) 
                dw=0;
        }
        if(dw) {
            if(better.empty()||ans.size()<better.size()) {
                better=ans;
            }
        }
    }

    cout << better.size() << "\n";
    for(int i : better) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	while(T--) {
        solve();
	}
}