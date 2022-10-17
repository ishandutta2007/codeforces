#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("txt.in", "r", stdin);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        deque<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        int zeroes = 0;
        while (a.size() > 1){
            deque<int> b;
            for (int i = 1; i < a.size(); ++i){
                b.push_back(a[i] - a[i - 1]);
            }
            sort(b.begin(), b.end());
            if (zeroes && b[0] != 0){
                zeroes--;
                b.push_front(0);
            }
            while (b.size() > 1 && b[1] == 0){
                b.pop_front();
                zeroes++;
            }
            swap(a, b);
            // for (int i = 1; i <= zeroes; ++i) cout << 0 << " ";
            // for (int x : a) cout << x << " ";
            // cout << '\n';
        }
        if (a.size() == 1) cout << a[0] << '\n';
        else cout << 0 << '\n';
    }
}