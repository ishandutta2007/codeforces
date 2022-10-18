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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    map<int, int, greater<int>> count;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(sum + t <= m){
            cout << "0 ";
        }
        else{
            int ans = 0;
            int mt = sum + t - m;
            for(pair<int, int> p : count){
                if(mt <= 0){
                    break;
                }
                int temp = min(p.second, (int)ceil((double)mt / p.first));
                ans += temp;
                mt -= temp * p.first;
            }
            cout << ans << " ";
        }
        sum += t;
        count[t]++;
    }

    return 0;
}