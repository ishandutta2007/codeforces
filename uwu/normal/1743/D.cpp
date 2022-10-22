#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    if (s.empty()){
        cout << 0 << '\n';
        return 0;
    }
    N = s.size();
    int T = min(30, N);
    vector<string> a(T);
    for (int i = 0; i < T; ++i){
        string x = s;
        string y = s;
        for (int j = 0; j < i; ++j) y.pop_back();
        while (y.size() < x.size()) y = "0" + y;
        // cout << x << " " << y << '\n';
        for (int j = 0; j < N; ++j){
            if (x[j] == '1' || y[j] == '1') a[i].push_back('1');
            else a[i].push_back('0');
        }
    }
    sort(a.begin(), a.end(), greater<string>());
    cout << a[0] << '\n';
}