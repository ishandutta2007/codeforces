//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        int n;
        cin >> n;
        vector<string> a(2);
        cin >> a[0] >> a[1];

        int d = 3; //1:up 2:down 3:right
        int nx = 0, ny = 0;
        bool ans = true;
        while(true){
            //cerr << nx << "," << ny << " " << d << "\n";
            if(nx == 1 && ny == n) break;
            else if((nx != 1 && nx != 0) || ny < 0 || ny >= n){
                ans = false;
                break;
            }
            if(a[nx][ny] > '2'){
                if(d == 3){
                    if(nx == 0) d = 2;
                    else d = 1;
                }
                else d = 3;
            }
            //cerr << d << "\n";

            if(d == 1) nx--;
            else if(d == 2) nx++;
            else ny++;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}