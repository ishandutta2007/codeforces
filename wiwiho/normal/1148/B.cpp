#include <bits/stdc++.h>

#define cont(a) a.begin(), a.end()
#define lsort(a) sort(cont(a))
#define gsort(a) sort(cont(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int ans = -1;

    if(k >= n || k >= m){
        goto print;
    }

    for(int i = 0; i <= k; i++){
        auto it = lower_bound(cont(b), a[i] + ta);
        int t = it - b.begin();
        if(k - i >= m - t){
            ans = -1;
            break;
        }

        ans = max(ans, b[t + k - i] + tb);
    }

    print:
    cout << ans << "\n";
    
    return 0;
}