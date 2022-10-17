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
        vector<int> arr(n);
        int odd=0,even=0;
        for (int i=0;i<n;++i){
            cin >> arr[i];
            if (arr[i]%2==0) even++;
            else odd++;
        }
        if (even%2==1){
            sort(arr.begin(),arr.end());
            bool yes=0;
            for (int i=0;i<n;++i){
                yes|=(arr[i]+1==arr[i+1]);
            }
            if (yes) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
        else{
            cout << "yes" << '\n';
        }
    }
}