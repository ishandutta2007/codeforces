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

int countS = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> up(n);
    vector<int> down(n);
    ll count = 0;
    for(int i = 0; i < n; i++){
        double a;
        cin >> a;
        up[i] = ceil(a);
        down[i] = floor(a);
        count += down[i];
    }

    int t = -count;
    for(int i = 0; i < n; i++){
        if(t > 0 && up[i] != down[i]){
            cout << up[i] << "\n";
            t--;
        }
        else{
            cout << down[i] << "\n";
        }
    }

    return 0;
}