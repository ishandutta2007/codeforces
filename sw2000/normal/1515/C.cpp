#include<bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 10;

int n,m,x;
pii arr[N];
int ans[N];
void solve(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i].fi;
        arr[i].se=i;
    }
    sort(arr,arr+n,greater<pii>());
    set<pii>s;
    for(int i=1;i<=m;i++)s.insert({0,i});
    for(int i=0;i<n;i++){
        pii u=*s.begin();s.erase(u);
        ans[arr[i].se]=u.se;
        u.fi+=arr[i].fi;
        s.insert(u);
    }

    if(s.rbegin()->fi-s.begin()->fi>x){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
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