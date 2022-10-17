#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        string a, b; cin >> a >> b;
        while (!a.empty() && !b.empty() && a.back() == b.back()){
            a.pop_back();
            b.pop_back();
        }
        if (b.size() == 1){
            if (a.find(b[0]) != a.npos){
                b = "";
            }
        }
        cout << (b.size() == 0 ? "YES" : "NO") << '\n';
    }
}