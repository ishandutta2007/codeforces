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
        string uwu; cin >> uwu;
        int ans=uwu.size()-2;
        for (int i=0;i<=9;++i){
            for (int j=0;j<=9;++j){
                int cnt=0; bool flag=0;
                for (char x:uwu){
                    if (x==i+'0'&&!flag) cnt++, flag^=1;
                    else if (x==j+'0'&&flag) cnt++, flag^=1;
                }
                if ((cnt)%2==1&&i!=j) cnt--;
                ans=min(ans,(int)uwu.size()-cnt);
            }
        }
        cout << ans << '\n';
    }
}