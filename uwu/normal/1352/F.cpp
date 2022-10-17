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
        int n0,n1,n2; cin >> n0 >> n1 >> n2;
        if (n1%2==0&&n1!=0){
            cout << "01";
            n1--;
        }
        else if (n1==0&&n2==0) cout << 0;
        else cout << "1";
        for (int i=0;i<n2;++i){
            cout << 1;
        }
        for (int i=0;i<n1;++i){
            cout << i%2;
        }
        for (int i=0;i<n0;++i){
            cout << 0;
        }
        cout << '\n';
    }
}