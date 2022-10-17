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
        string a,b; cin >> a >> b;
        a=" "+a; b=" "+b;
        vector<int> ans;
        int uwu1=1,uwu2=n;
        for (int i=0;i<=n-1;++i){
            if ((a[uwu1]-'0')^(i%2)==(b[n-i]-'0')) ans.push_back(1);
            ans.push_back(n-i);
            swap(uwu1,uwu2);
            if (i%2==0) uwu2++;
            if (i%2==1) uwu2--;

        }
        cout << ans.size() << " ";
        for (int x:ans) cout << x << " ";
        cout << '\n';
    }
}