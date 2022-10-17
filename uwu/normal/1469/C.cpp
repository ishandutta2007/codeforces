#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int h[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        cin >> h[1];
        int l=h[1], r=h[1];
        bool ans=1;
        for (int i=2;i<=n;++i){
            cin >> h[i];
            int cl=max(h[i],l+1-k), cr=min(h[i]+k-1,r+k-1);
            if (i==n) cl=cr=h[i];
            if (cl>cr) ans=0;
            if (cl>=r+k||cr+k<=l) ans=0;
            l=cl, r=cr;
        }
        cout << (ans?"Yes":"No") << '\n';
    }
}