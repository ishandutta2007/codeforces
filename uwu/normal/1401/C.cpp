#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int gcd(int a, int b){ return (b==0?a:gcd(b,a%b)); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1), good(n+1);
        for (int i=1;i<=n;++i) cin >> arr[i], good[i]=arr[i];
        sort(good.begin(),good.end());
        int small=good[1];
        bool flag=1;
        for (int i=1;i<=n;++i){
            if (arr[i]!=good[i]) flag&=arr[i]%small==0;
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}