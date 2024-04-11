#include<bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=int(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=n;i--)
#define endl '\n'
using ll=long long;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<ll>a(n);
        rep(i,0,n)cin>>a[i];
        vector<bool>used(n);
        ll now=0;
        vector<ll>ret;
        while(1){
            ll mx=0;
            ll idx=0;
            rep(i,0,n){
                if(chmax(mx,(~now&((1LL<<60)-1))&a[i])){
                    idx=i;
                }
            }
            if(mx==0)break;
            now|=mx;
            used[idx]=true;
            ret.push_back(a[idx]);
        }
        rep(i,0,n)if(!used[i])ret.push_back(a[i]);
        rep(i,0,n){
            cout<<ret[i];
            if(i==n-1)cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}