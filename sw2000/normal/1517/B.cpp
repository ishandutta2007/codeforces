#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

int n,m,k,arr[110][110],ans[110][110];
void solve(){
    cin>>n>>m;
    vector<pii>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            ans[i][j]=0;
            v.push_back({arr[i][j],i});
        }
    }
    sort(v.begin(),v.end());
    vi brr[110];
    for(int i=m;i<v.size();i++){
        brr[v[i].se].push_back(v[i].fi);
    }
    for(int i=0;i<m;i++){
        ans[v[i].se][i]=v[i].fi;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(!ans[i][j]){
            ans[i][j]=brr[i].back();
            brr[i].pop_back();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
	return 0;
}