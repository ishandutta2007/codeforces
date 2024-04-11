#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
 
int a, b, x;
cin >> a >> b >> x;

int k = (a < b);
string ans;

rep(i, 0, x+1) {
if (i%2 == k) {
a--; ans.pb(0x30);
} else {
b--; ans.pb(0x31);
}
}

while (a > 0) {
ans.insert(find(all(ans), 0x30), 0x30); a--;
}

while (b > 0) {
ans.insert(find(all(ans), 0x31), 0x31); b--;
}
cout << ans << endl;
    return 0;
}