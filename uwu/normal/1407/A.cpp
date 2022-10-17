#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int cnt0=0,cnt1=0;
        for (int i=1,a;i<=n;++i){
            cin >> a;
            if (a==0) cnt0++;
            else cnt1++;
        }
        int rem0=0,rem1=0;
        if (cnt0>=cnt1){
            rem1=cnt1;
        }
        else{
            rem0=cnt0;
            if (rem0%2==1) rem1=1;
        }
        cout << n-rem1-rem0 << '\n';
        for (int i=1;i<=cnt1-rem1;++i) cout << 1 << " ";
        for (int i=1;i<=cnt0-rem0;++i) cout << 0 << " ";
        cout << '\n';
    }
}