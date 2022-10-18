#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> p(m);
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }

    int ans = 0;

    ll pagestart = 1;
    ll nowk = k;
    for(int i = 0; i < m ; i++){

        if(p[i] > pagestart + nowk - 1){
            pagestart += nowk;
            nowk = k;
            if(p[i] > pagestart + nowk - 1){
                pagestart += ceil((p[i] - (pagestart + nowk - 1)) / k) * k;
                if(p[i] > pagestart + nowk - 1){
                    pagestart += k;
                }
            }
        }

        int j;
        for(j = i + 1; j < m; j++){
            if(p[j] > pagestart + nowk - 1){
                break;
            }
        }
        nowk += j - i;
        i = j - 1;
        ans++;

    }

    cout << ans << "\n";


    return 0;
}