#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 600+10;
const int mod=998244353;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        vi v(n);
        for(auto &i:v)cin>>i;
        sort(v.begin(),v.end());
        int ans=0,mi=inf;
        for(int i=1;i<n&&v[i]<=0;i++){
            mi=min(mi,v[i]-v[i-1]);
        }
        for(auto i:v){
            if(i<=0)ans++;
            else{
                if(i<=mi)ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
}