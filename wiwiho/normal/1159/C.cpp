#include <bits/stdc++.h>

#define lsort(a) sort(a.begin(), a.end())
#define gsort(a) sort(a.rbegin(), a.rend())

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    ll bsum = 0;
    ll bmax = 0;
    ll bmax2 = 0;
    for(int i = 0; i < n; i++){
        ll b;
        cin >> b;
        bsum += b;

        if(b > bmax){
            bmax2 = bmax;
            bmax = b;
        }
        else if(b > bmax2){
            bmax2 = b;
        }
    }

    ll gsum = 0;
    ll gmin = 1e8;
    for(int i = 0; i < m; i++){
        ll g;
        cin >> g;
        gsum += g;
        gmin = min(gmin, g);
    }

    if(gmin < bmax){
        cout << "-1\n";
        return 0;
    }

    if(gmin > bmax){
        cout << (m * bsum + gsum - bmax * (m - 1) - bmax2) << "\n";
    }
    else{
        cout << (m * bsum + gsum - bmax * m) << "\n";
    }
    
    return 0;
}