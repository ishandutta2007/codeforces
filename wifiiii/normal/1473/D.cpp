#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 200005;
int pmn[maxn], pmx[maxn], p[maxn];
int smn[maxn], smx[maxn], s[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string S;
        cin >> S;
        int pre = 0;
        pmn[0] = pmx[0] = smn[n+1] = smx[n+1] = 0;
        for(int i=1;i<=n;++i) {
            if(S[i-1] == '+') {
                pre += 1;
            } else {
                pre -= 1;
            }
            p[i] = pre;
            pmn[i] = min(pmn[i-1], pre);
            pmx[i] = max(pmx[i-1], pre);
        }
        for(int i=n;i>=1;--i) {
            if(S[i-1] == '+') {
                smx[i] = max(smx[i+1], 0) + 1;
                smn[i] = smn[i+1] + 1;
            } else {
                smx[i] = smx[i+1] - 1;
                smn[i] = min(smn[i+1], 0) - 1;
            }
        }
        while(q--) {
            int l,r;
            cin >> l >> r;
            int L = pmn[l-1], R = pmx[l-1];
            L = min(L, p[l-1] + smn[r+1]);
            R = max(R, p[l-1] + smx[r+1]);
            cout << R - L + 1 << endl;
        }
    }
}


//int main() {
//    int t;
//    cin >> t;
//    while(t--) {
//        // 5 3
//        // 1 2 3 2 1
//        // 6 2
//        // 6 4
//        // 1 2 3 4 3 2 (2k-n)
//    }
//}