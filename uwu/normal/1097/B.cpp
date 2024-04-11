#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=15;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i) cin >> arr[i];
    for (int i=0;i<(1<<n);++i){
        int theta=0;
        for (int j=0;j<n;++j){
            if (1&(i>>j)) theta+=arr[j];
            else theta-=arr[j];
        }
        if (theta%360==0){ cout << "YES" << '\n'; return 0; }
    }
    cout << "NO" << '\n';
}