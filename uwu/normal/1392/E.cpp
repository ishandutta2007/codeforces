#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=27;

ll arr[MAXN][MAXN];

int main(){
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (i+j!=2) arr[i][j]=((ll)(i%2==1))*(1LL<<(i+j-3));
            cout << arr[i][j] << " ";
        }
        cout << '\n';
        cout.flush();
    }
    int q; cin >> q;
    while (q--){
        ll val; cin >> val;
        int x=1,y=1;
        cout << x << " " << y << '\n';
        cout.flush();
        for (int i=3;i<=2*n;++i){
            bool yes=(1LL&(val>>(i-3)));
            if (yes){
                if (arr[x+1][y]!=0&&x+1<=n) x++;
                else y++;
            }
            else{
                if (arr[x+1][y]==0&&x+1<=n) x++;
                else y++;
            }
            cout << x << " " << y << '\n';
            cout.flush();
        }
    }
}