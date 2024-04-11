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

int l[1000005];
int r[1000005];
bool d[1000005];
int arr[1000005];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    int b[n - 1];
    memset(b, -1, sizeof(int) * (n - 1));

    vector<pair<int, int>> nosort;

    for(int i = 0; i < m; i++){
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if(t == 1){
            memset(b + l, 0, sizeof(int) * (r - l));
        }
        else{
            nosort.pb(mp(l, r));
        }
    }

    bool ans = true;
    for(pair<int, int> p : nosort){
        for(int i = p.first; i < p.second; i++){
            if(b[i] == -1){
                goto next;
            }
        }
        ans = false;
        break;
        next:;
    }

    if(ans){
        cout << "YES\n";
        int last = 10000;
        cout << last << "\n";
        for(int i = 0; i < n - 1; i++){
            last += b[i];
            cout << last << "\n";
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
}