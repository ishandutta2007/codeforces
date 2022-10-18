#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5, inf = 1e9 + 7;

int n; ll ans;
string s, t;
int cost[N];

void readTest(){
    cin >> s; n = s.length();
    For(i, 0, n){
        if (s[i] == '('){
            cost[i] = inf;
            t += '(';
        }
        else if (s[i] == ')'){
            cost[i] = inf;
            t += ')';
        }
        else{
            int x, y; cin >> x >> y;
            if (x < y){
                ans += x;
                cost[i] = y - x;
                t += '(';
            }
            else{
                ans += y;
                cost[i] = x - y;
                t += ')';
            }
        }
    }
}

set <pii> sttOpen, sttClose;
int bal;

void resetTest(){
    
}

string rev(string s){
    string ans;
    FordE(i, isz(s) - 1, 0){
        if (s[i] == ')'){
            ans += '(';
        }
        else{
            ans += ')';
        }
    }
    return ans;
}

void solveTest(){
    if (n % 2 == 1){
        cout << -1 << endl;
        return;
    }
    int open = 0, close = 0;
    For(i, 0, n){
        if (t[i] == '('){
            open++;
        }
        else{
            close++;
        }
    }
    if (open > close){
        int diff = (open - close) / 2;
        priority_queue <pii, vpii, greater <pii>> pq;
        For(i, 0, n){
            if (t[i] == '('){
                pq.push(make_pair(cost[i], i));
            }
        }
        ForE(i, 1, diff){
            pii cac = pq.top(); pq.pop();
            if (cac.fi == inf){
                cout << -1 << endl;
                return;
            }
            ans += cac.fi;
            cost[cac.se] = -cac.fi;
            t[cac.se] = ')';
        }
    }
    else if (close > open){
        int diff = (close - open) / 2;
        priority_queue <pii, vpii, greater <pii>> pq;
        For(i, 0, n){
            if (t[i] == ')'){
                pq.push(make_pair(cost[i], i));
            }
        }
        ForE(i, 1, diff){
            pii cac = pq.top(); pq.pop();
            if (cac.fi == inf){
                cout << -1 << endl;
                return;
            }
            ans += cac.fi;
            cost[cac.se] = -cac.fi;
            t[cac.se] = '(';
        }
    }
    // cout << ans << ' ' << t << endl;
    sttOpen.clear(); sttClose.clear();
    For(i, 0, n){
        if (t[i] == '('){
            sttOpen.insert(make_pair(cost[i], i));
        }
    }
    bal = 0;
    For(i, 0, n){
        if (t[i] == '('){
            sttOpen.erase(sttOpen.find(make_pair(cost[i], i)));
            bal++;
        }
        else{
            sttClose.insert(make_pair(cost[i], i));
            bal--;
        }
        if (bal == -1){
            // cout << "A " << ans << ' ' << t << ' ' << i << endl;
            if (isz(sttOpen) == 0 || isz(sttClose) == 0){
                cout << -1 << endl;
                return;
            }
            pii costOpen = *sttOpen.begin(); sttOpen.erase(sttOpen.begin());
            pii costClose = *sttClose.begin(); sttClose.erase(sttClose.begin());
            // cout << costOpen.fi << ' ' << costOpen.se << ' ' <<
            //         costClose.fi << ' ' << costClose.se << endl;
            if (costOpen.fi == inf || costClose.fi == inf){
                cout << -1 << endl;
                return;
            }
            ans += costOpen.fi; t[costOpen.se] = ')'; cost[costOpen.se] = -costOpen.fi;
            ans += costClose.fi; t[costClose.se] = '('; cost[costClose.se] = -costClose.fi;
            bal += 2;
        }
    }
    t = rev(t);
    reverse(cost, cost + n);
    // cout << ans << ' ' << t << endl;
    sttOpen.clear(); sttClose.clear();
    For(i, 0, n){
        if (t[i] == '('){
            sttOpen.insert(make_pair(cost[i], i));
        }
    }
    bal = 0;
    For(i, 0, n){
        if (t[i] == '('){
            sttOpen.erase(sttOpen.find(make_pair(cost[i], i)));
            bal++;
        }
        else{
            sttClose.insert(make_pair(cost[i], i));
            bal--;
        }
        if (bal == -1){
            // cout << "B " << ans << ' ' << t << ' ' << i << endl;
            if (isz(sttOpen) == 0 || isz(sttClose) == 0){
                cout << -1 << endl;
                return;
            }
            pii costOpen = *sttOpen.begin(); sttOpen.erase(sttOpen.begin());
            pii costClose = *sttClose.begin(); sttClose.erase(sttClose.begin());
            // cout << costOpen.fi << ' ' << costOpen.se << ' ' <<
            //         costClose.fi << ' ' << costClose.se << endl;
            if (costOpen.fi == inf || costClose.fi == inf){
                cout << -1 << endl;
                return;
            }
            ans += costOpen.fi; t[costOpen.se] = ')'; cost[costOpen.se] = -costOpen.fi;
            ans += costClose.fi; t[costClose.se] = '('; cost[costClose.se] = -costClose.fi;
            bal += 2;
        }
    }
    t = rev(t);
    reverse(cost, cost + n);
    cout << ans << endl;
    cout << t << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
// int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
// }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/