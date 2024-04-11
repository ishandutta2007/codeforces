#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n+1),b(n+1);
        bool marked[n+1]={0};
        for (int i=1;i<=n;++i) cin >> a[i];
        for (int i=1;i<=n;++i) cin >> b[i];
        bool ans=true;
        if (n%2==1) ans&=(a[(n+1)/2]==b[(n+1)/2]);
        for (int i=1;i<=n/2;++i){
            bool can=false;
            for (int k=1;k<=n/2;++k){
                if (((a[i]==b[k]&&a[n-i+1]==b[n-k+1])||(a[i]==b[n-k+1]&&a[n-i+1]==b[k]))&&!marked[k]){
                    marked[k]=1;
                    can=true;
                    break;
                }
            }
            ans&=can;
        }
        if (ans) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}