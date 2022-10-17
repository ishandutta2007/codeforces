#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e4 + 1;

int ans[MN];
int ask(int i){
    cout << "? " << i << '\n';
    cout.flush();
    int x; cin >> x;
    if (x == 0) exit(0);
    return x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        for (int i = 1; i <= N; ++i) ans[i] = 0;
        for (int i = 1; i <= N; ++i){
            if (ans[i]) continue;
            int x = 0;
            while (x != i){
                x = ask(i);
            }
            do{
                int tmp = ask(i);
                ans[x] = tmp;
                x = tmp;
            } while (x != i);
        }
        cout << "! ";
        for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
        cout << '\n';
        cout.flush();
    }
}