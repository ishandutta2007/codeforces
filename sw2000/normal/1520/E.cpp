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
const int mod = 1e9+7;

ll solve(){
    int n;string s;cin>>n>>s;
    int cnt=0;
    for(auto i:s)if(i=='*')cnt++;
    ll ret=0,now=0;
    for(auto i:s){
        if(i=='*')now++;
        else ret+=min(now,cnt-now);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
	return 0;
}