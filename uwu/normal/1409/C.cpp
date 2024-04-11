#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,x,y; cin >> n >> x >> y;
        int best=0x3f3f3f3f,ans1,ans2,curr;
        for (int i=1;i<=x;++i){
            for (int j=1;j<=y-x;++j){
                curr=i+j*(n-1);
                if ((x-i)%j!=0||(y-i)%j!=0||curr<y) continue;
                if (best>curr) best=curr, ans1=i, ans2=j;
            }
        }
        for (int i=ans1;i<=best;i+=ans2){
            cout << i << " ";
        }
        cout << '\n';
    }
}