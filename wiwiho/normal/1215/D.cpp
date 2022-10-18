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

    string s;
    cin >> s;

    int sum1 = 0, sum2 = 0;
    int c1 = 0, c2 = 0;

    for(int i = 0; i < n / 2; i++){
        if(s[i] == '?') c1++;
        else sum1 += s[i] - '0';
    }
    for(int i = n / 2; i < n; i++){
        if(s[i] == '?') c2++;
        else sum2 += s[i] - '0'; 
    }

    if(c1 > c2){
        swap(c1, c2);
        swap(sum1, sum2);
    }

    int c = c2 - c1;
    int d = sum1 - sum2;
    //cerr << c << " " << d << "\n";
    if(d == (c / 2) * 9) cout << "Bicarp\n";
    else cout << "Monocarp\n";

    return 0;
}