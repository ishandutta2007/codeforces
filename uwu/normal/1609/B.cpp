#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

string s;
int cnt;
void update(int i, int v){
    if (i <= 0 || i + 2 >= s.size()) return;
    if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
        cnt += v;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    cin >> s; s = (" " + s);
    for (int i = 1; i <= N; ++i) update(i, 1);
    while (Q--){
        int i; char c;
        cin >> i >> c;
        update(i - 2, -1);
        update(i - 1, -1);
        update(i, -1);
        s[i] = c;
        update(i - 2, 1);
        update(i - 1, 1);
        update(i, 1);
        cout << cnt << '\n';
    }
}