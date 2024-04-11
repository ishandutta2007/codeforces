//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(k);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "?") a[i % k].eb(-MAX);
        else a[i % k].eb(stoi(s));
    }


    for(int i = 0; i < k; i++){
        int lst = -1;
        int cnt = 0;
        a[i].eb(1005000001);
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == -MAX){
                cnt++;
                continue;
            }
            ll lstv = lst == -1 ? -1005000001 : a[i][lst];

            if(a[i][j] - lstv - 1 < cnt){
                cout << "Incorrect sequence\n";
                return 0;
            }

            if(lstv < 0 && a[i][j] <= 0){
                int now = a[i][j] - 1;
                for(int l = j - 1; l > lst; l--){
                    a[i][l] = now--;
                }
            }
            else if(lstv >= 0 && a[i][j] > 0){
                int now = lstv + 1;
                for(int l = lst + 1; l < j; l++){
                    a[i][l] = now++;
                }
            }
            else{
                int now = cnt / 2;
                if(now >= a[i][j]) now = a[i][j] - 1;
                else if(now - cnt + 1 <= lstv) now = lstv + cnt;

                for(int l = j - 1; l > lst; l--){
                    a[i][l] = now--;
                }
            }

            cnt = 0;
            lst = j;
        }
    }

    for(int i = 0; i < n; i++){
        cout << a[i % k][i / k] << " ";
    }
    cout << "\n";

    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***

//      *   * ***** *   * ***** *   * *****
//     *   *   *   *   *   *   *   * *   *
//    *   *   *   *   *   *   ***** *   *
//   * * *   *   * * *   *   *   * *   *
//   * *  *****  * *  ***** *   * *****