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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    deque<int> a(n);
    int ma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
    }

    int t = 0;
    vector<pair<int, int>> ans;
    while(a[0] != ma){
        int A = a.front();
        a.pop_front();
        int B = a.front();
        a.pop_front();
        if(A > B){
            a.push_front(A);
            a.push_back(B);
        }
        else{
            a.push_front(B);
            a.push_back(A);
        }

        ans.pb(mp(A, B));
        t++;
    }

    int tt = 0;
    deque<int> tv(a.begin(), a.end());
    while(a != tv || tt == 0){
        int A = a.front();
        a.pop_front();
        int B = a.front();
        a.pop_front();
        if(A > B){
            a.push_front(A);
            a.push_back(B);
        }
        else{
            a.push_front(B);
            a.push_back(A);
        }

        ans.pb(mp(A, B));
        tt++;
    }

    cerr << t << " " << tt << "\n";

    for(int i = 0; i < q; i++){
        ll m;
        cin >> m;

        if(m <= t){
            cout << ans[m - 1].first << " " << ans[m - 1].second << "\n";
            continue;
        }
        m -= t;
        m -= 1;
        m %= tt;
        m += t + 1;
        cout << ans[m - 1].first << " " << ans[m - 1].second << "\n";
    }


    return 0;
}