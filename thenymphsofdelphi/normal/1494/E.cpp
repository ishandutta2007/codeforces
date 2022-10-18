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

const int N = 2e5 + 5;

int n, q;

map <pair <int, int>, char> mpp;
int ans1, ans2;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    while (q--){
        char que; cin >> que;
        if (que == '+'){
            int u, v; char c;
            cin >> u >> v >> c;
            mpp[make_pair(u, v)] = c;
            if (mpp.find(make_pair(v, u)) != mpp.end()){
                ans2++;
                if (mpp[make_pair(v, u)] == c){
                    ans1++;
                }
            }
        }
        else if (que == '-'){
            int u, v;
            cin >> u >> v;
            if (mpp.find(make_pair(v, u)) != mpp.end()){
                ans2--;
                if (mpp[make_pair(v, u)] == mpp[make_pair(u, v)]){
                    ans1--;
                }
            }
            mpp.erase(make_pair(u, v));
        }
        else{
            int k; cin >> k;
            if (k % 2 == 1){
                if (ans2){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
            else{
                if (ans1){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }
    }
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