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
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int one = 0;
    int zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            zero++;
        }
        else{
            one++;
        }
    }

    if(one != zero){
        cout << "1\n" << s << "\n";
    }
    else{
        cout << "2\n" << s.substr(0, n - 1) << " " << s[n - 1] << "\n";
    }

    return 0;
}