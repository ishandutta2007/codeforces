#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n==1){
        cout << "! 1" << '\n';
        cout.flush();
        return 0;
    }
    int ans[n+1]={0}; int last=1;
    for (int i=2,a,b;i<=n;++i){
        cout << "? " << last << " " << i << '\n'; cout.flush();
        cin >> a;
        cout << "? " << i << " " << last << '\n'; cout.flush();
        cin >> b;
        if (b>a) ans[i]=b;
        if (a>b) ans[last]=a, last=i;
    }
    cout << "! ";
    for (int i=1;i<=n;++i){
        if (ans[i]==0) cout << n << " ";
        else cout << ans[i] << " ";
    }
    cout << '\n'; 
    cout.flush();
}