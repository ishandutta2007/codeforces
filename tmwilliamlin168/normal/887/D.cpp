#include <bits/stdc++.h>
       
using namespace std;
       
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double
 
int n, a, b, c, d, start, len;
pair<int, int> q[300007];
ll pref1[300007], pref2[300007];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> c >> d >> start >> len;
    for (int i = 1; i <= n; i++) cin >> q[i].x >> q[i].y;
 
    q[0] = mp(-1, -1);
    //sort(q + 1, q + n + 1);
 
    pref1[0] = start; pref2[0] = start;
    for (int i = 1; i <= n; i++){
        if (q[i].y == 0){
            pref1[i] = pref1[i - 1] - b;
            pref2[i] = pref2[i - 1] - d;
        } else {
            pref1[i] = pref1[i - 1] + a;
            pref2[i] = pref2[i - 1] + c;
        }
    }
 
    multiset<ll> se;
    int uk = 1;
 
    for (int i = 0; i <= n; i++){
        if (pref1[i] < 0) cout << -1, exit(0);
 
        if (i) se.erase(se.find(pref2[i]));
        while(uk <= n && q[uk].x - (q[i].x + 1) < len) se.insert(pref2[uk++]);
 
        if (se.size() == 0) cout << q[i].x + 1, exit(0);
        ll val = *se.begin();
        val += pref1[i] - pref2[i];
        if (val >= 0) cout << q[i].x + 1, exit(0);
    }
}