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

ll ans = 0;

void check(vector<pair<int, int>>& a, int pos){
    vector<pair<int, int>> b;
    for(int i = 0; i < a.size(); i++){
        if(i != pos){
            b.pb(a[i]);
        }
    }

    if(b.size() <= 2){
        cout << a[pos].second << "\n";
        exit(0);
    }

    int d = b[1].first - b[0].first;
    for(int i = 1; i < b.size() - 1; i++){
        if(b[i + 1].first - b[i].first != d){
            return;
        }
    }
    cout << a[pos].second << "\n";
    exit(0);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    lsort(a);

    int d = 0;
    for(int i = 0; i < n - 1; i++){
        int t = a[i + 1].first - a[i].first;
        d = max(d, t);
    }

    check(a, 0);
    check(a, n - 1);
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1].first - a[i].first != d){
            check(a, i + 1);
            break;
        }
    }

    cout << "-1\n";

    return 0;
}