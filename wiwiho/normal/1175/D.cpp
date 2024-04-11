#include <bits/stdc++.h>

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

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 1000000001

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> s;
    ll sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += a[i];
        if(i > 0){
            s.pb(sum);
        }
    }

    gsort(s);
    for(int i = 0; i < k - 1; i++){
        sum += s[i];
    }

    cout << sum << "\n";
    
    return 0;
}