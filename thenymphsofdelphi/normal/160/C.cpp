
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 1e5 + 5;

int n, k;
int a[N];
map <int, int> mpp;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mpp[a[i]]++;
    }
    int tmp;
    for (auto v: mpp){
        if (v.se * n < k){
            k -= v.se * n;
        }
        else{
            cout << v.fi << ' ';
            tmp = v.se;
            break;
        }
    }
    for (auto v: mpp){
        if (tmp * v.se < k){
            k -= tmp * v.se;
        }
        else{
            cout << v.fi;
            return 0;
        }
    }
}