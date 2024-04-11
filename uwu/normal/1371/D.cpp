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
        int n,k; cin >> n >> k;
        bool arr[n][n];
        ms(arr,0);
        cout << (k%n==0?0:2) << '\n';
        for (int i=0;i<n;++i){
            if (k==0) break;
            for (int j=0;j<n;++j){
                arr[j][(i+j)%n]=1; k--;
                if (k==0) break;
            }
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                cout << arr[i][j];
            }
            cout << '\n';
        }
    }
}