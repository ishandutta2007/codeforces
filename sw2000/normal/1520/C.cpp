#include<bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const int mod = 220000607;
int ans[110][110];
void solve(){
    int n;cin>>n;
    if(n==2){cout<<-1<<endl;return;}
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=2-i%2;j<=n;j+=2){
            ans[i][j]=++tot;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i%2+1;j<=n;j+=2){
            ans[i][j]=++tot;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
	return 0;
}