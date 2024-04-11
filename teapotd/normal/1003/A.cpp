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
    
int n; cin >> n;
map<int, int> kek;
int ans = 0;
rep(i,0,n){
int k; cin >> k;
ans = max(ans, ++kek[k]);
}
cout << ans << endl;

    return 0;
}