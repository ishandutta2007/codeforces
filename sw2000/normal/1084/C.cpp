#include<bits/stdc++.h>
#define fi first
#define se second
//#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    string s;cin>>s;
    vi v;
    int ca=0,cb=0;
    for(auto i:s){
        if(i=='a'){
            ca++;
            cb=0;
        }
        else if(i=='b'){
            cb++;
            if(ca){
                v.push_back(ca);
                ca=0;
            }
        }
    }
    if(ca)v.push_back(ca);
    ll ans=1;
    for(auto i:v)ans=ans*(i+1)%mod;
    ans=(ans-1+mod)%mod;
    cout<<ans;
	return 0;
}