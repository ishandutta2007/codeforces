#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,y, sz, t;
string s;
ll a[555555], b[555555];
multiset<ll> A, B;
int main()
{
    //freopen("input.txt", "r", stdin);
    //cin >> s;
    //cout << s.find("hyu") << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        B.insert(b[i]);
    }
    ll cur_move = 0;
    ll ansa = 0, ansb = 0;
    while (!A.empty() || !B.empty()) {
        if (cur_move == 0) {
            if (A.empty()) {
                auto itr = B.end();
                itr--;
                B.erase(itr);
            } else if (B.empty()) {
                auto itr = A.end();
                itr--;
                ansa += *itr;
                A.erase(itr);
            } else {
                auto itr = A.end();
                itr--;
                ll maxa = *itr;
                itr = B.end();
                itr--;
                ll maxb = *itr;
                if (maxa > maxb) {
                    itr = A.end();
                    itr--;
                    ansa += maxa;
                    A.erase(itr);
                } else {
                    itr = B.end();
                    itr--;
                    B.erase(itr);
                }
            }
        } else {
            if (A.empty()) {
                auto itr = B.end();
                itr--;
                ansb += *itr;
                B.erase(itr);
            } else if (B.empty()) {
                auto itr = A.end();
                itr--;
                A.erase(itr);
            } else {
                auto itr = A.end();
                itr--;
                ll maxa = *itr;
                itr = B.end();
                itr--;
                ll maxb = *itr;
                if (maxa > maxb) {
                    itr = A.end();
                    itr--;
                    A.erase(itr);
                } else {
                    itr = B.end();
                    itr--;
                    ansb += *itr;
                    B.erase(itr);
                }
            }
        }
        cur_move ^= 1;
    }
    cout << ansa - ansb << endl;
	return 0;
}