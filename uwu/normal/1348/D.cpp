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
        vector<int> arr;
        int tot=0;
        for (int i=1;i*2<=n;i*=2){
            arr.push_back(i);
            tot+=i;
        }
        if (tot!=n) arr.push_back(n-tot);
        sort(arr.begin(),arr.end());
        if (arr.size()==1){
            cout << 1 << '\n' << 0;
        }
        else{
            cout << arr.size()-1 << '\n';
            for (int i=1;i<arr.size();++i){
                cout << arr[i]-arr[i-1] << " ";
            }
        }
        cout << '\n';
    }
}