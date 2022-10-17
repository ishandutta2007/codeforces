#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=4001;

int pos[MAXN];
bool dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1,a;i<=2*n;++i){
            cin >> a; pos[a]=i;
        }
        int curr=2*n+1;
        vector<int> items;
        for (int i=2*n;i>=1;--i){
            if (pos[i]<curr) items.push_back(curr-pos[i]),curr=pos[i];
        }
        ms(dp,0); dp[0]=1;
        for (int x:items){
            //cout << x << " ";
            for (int i=n;i>=x;--i) if (dp[i-x]) dp[i]=1;
        }
        cout << (dp[n]?"YES":"NO") << '\n';
    }
}