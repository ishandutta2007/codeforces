#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int ans=0;
    for (int i=1,a,b;i<=n;++i){
        cin >> a >> b;
        ans=max(ans,a+b);
    }
    cout << ans << '\n';
}