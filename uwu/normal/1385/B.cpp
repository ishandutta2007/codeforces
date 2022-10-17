#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=50;

bool arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> ans;
        for (int i=1,a;i<=2*n;++i){
            cin >> a;
            if (arr[a]==0) ans.push_back(a);
            arr[a]^=1;
        }
        for (int x:ans) cout << x << " ";
        cout << '\n';
    }
}