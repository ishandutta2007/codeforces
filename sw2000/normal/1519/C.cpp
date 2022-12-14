#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 10;

int n,arr[N];
ll ans[N],brr[N];
vi have[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)ans[i]=0;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)cin>>brr[i];
    for(int i=1;i<=n;i++){
        have[arr[i]].push_back(brr[i]);
    }
    for(int i=1;i<=n;i++){
        sort(have[i].begin(),have[i].end(),greater<int>());
        for(int j=1;j<have[i].size();j++){
            have[i][j]+=have[i][j-1];
        }
        for(int j=1;j<=have[i].size();j++){
            ans[j]+=have[i][have[i].size()/j*j-1];
        }
    }
    for(int i=1;i<=n;i++)have[arr[i]].clear();
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout<<endl;
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