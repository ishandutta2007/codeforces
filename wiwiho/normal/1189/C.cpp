#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

pair<ll, ll> a[20][100005];

int pow2(int n){
    return 1 << n;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int k = log2(n);
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a[0][i] = mp(0, t);
    }

    for(int i = 1; i <= k; i++){
        for(int j = 0; j + pow2(i) - 1 < n; j++){
            pair<ll, ll> t;
            t.second = (a[i - 1][j].second + a[i - 1][j + pow2(i - 1)].second) % 10;
            t.first = a[i - 1][j].first + a[i - 1][j + pow2(i - 1)].first;
            if(a[i - 1][j].second + a[i - 1][j + pow2(i - 1)].second >= 10){
                t.first++;
            }
            a[i][j] = t;
            //cerr << i << " " << j << " " << t.first << " " << t.second << "\n";
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << a[(int)log2(r - l + 1)][l - 1].first << "\n";
    }

    return 0;
}