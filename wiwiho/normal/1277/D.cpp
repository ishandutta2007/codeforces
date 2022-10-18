//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        map<string, int> index;
        int a00 = 0, a11 = 0, b= 0;
        vector<int> a01, a10;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(s[0] == '0' && s[s.size() - 1] == '0'){
                a00++;
                continue;
            }
            else if(s[0] == '1' && s[s.size() - 1] == '1'){
                a11++;
                continue;
            }
            string t = s;
            reverse(iter(t));
            auto it = index.find(t);
            if(it != index.end()) b++, it->S = -1;
            else index[s] = i;
        }

        for(auto& it : index){
            if(it.S == -1) continue;
            //cerr << it.F << " " << it.S << "\n";
            if(it.F[0] == '1' && it.F[it.F.size() - 1] == '0') a10.eb(it.S);
            else a01.eb(it.S);
        }

        if(a00 > 0 && a11 > 0 && a01.empty() && a10.empty() && b == 0){
            cout << "-1\n";
            continue;
        }

        //printv(a01, cerr);
        //printv(a10, cerr);
        if(a01.size() < a10.size()) swap(a01, a10);
        //printv(a01, cerr);
        //printv(a10, cerr);
        cout << max(0, ((int)a01.size() - (int)a10.size()) / 2) << "\n";
        for(int i = 0; i < ((int)a01.size() - (int)a10.size()) / 2; i++) cout << a01[i] + 1 << " ";
        cout << "\n";
    }



    return 0;
}