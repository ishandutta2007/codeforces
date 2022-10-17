#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        for (int i=1;i<=n;++i) cin >> arr[i];
        bool curr=true;
        for (int i=n-1;i>=1;--i){
            if (!curr) curr=1;
            else if (arr[i]==1&&curr) curr=0;
        }
        cout << (curr?"First":"Second") << '\n';
    }
}