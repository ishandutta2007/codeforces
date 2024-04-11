#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}}\
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
    
    string a, b;
    cin >> a >> b;

    int count = 0;
    int ans = 0;
    int t = 0;
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '1'){
            t++;
        }
        if(a[i] == '1'){
            count++;
        }
    }
    if((t + count) % 2 == 0){
        ans++;
    }

    for(int i = 1; i + b.size() - 1 < a.size(); i++){
        if(a[i - 1] == '1'){
            count--;
        }
        if(a[i + b.size() - 1] == '1'){
            count++;
        }
        if((t + count) % 2 == 0){
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}