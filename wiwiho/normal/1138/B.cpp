//#define NDEBUG
 
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
 
//#define TEST
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> va, vb, vc, vd;
    string sc, sa;
    cin >> sc >> sa;
    for(int i = 0; i < n; i++){
        if(sc[i] == '0' && sa[i] == '0'){
            va.pb(i + 1);
        }
        else if(sc[i] == '0' && sa[i] == '1'){
            vb.pb(i + 1);
        }
        else if(sc[i] == '1' && sa[i] == '0'){
            vc.pb(i + 1);
        }
        else if(sc[i] == '1' && sa[i] == '1'){
            vd.pb(i + 1);
        }
    }

    for(int c = 0; c <= vc.size(); c++){
        for(int b = 0; b <= vb.size(); b++){

            if((vb.size() + vd.size() - c - b) % 2 != 0) continue;
            int d = (vb.size() + vd.size() - c - b) / 2;
            if(d > vd.size()) continue;

            if(b + c + d > n / 2) continue;

            int a = n / 2 - b - c - d;
            if(a > va.size()) continue;

            for(int i = 0; i < a; i++) cout << va[i] << " ";
            for(int i = 0; i < b; i++) cout << vb[i] << " ";
            for(int i = 0; i < c; i++) cout << vc[i] << " ";
            for(int i = 0; i < d; i++) cout << vd[i] << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}