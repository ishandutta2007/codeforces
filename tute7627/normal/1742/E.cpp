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
        ll n,q;cin>>n>>q;
        vector<ll>a(n);
        rep(i,0,n)cin>>a[i];
        vector<ll>b(n+1),c(n+1);
        rep(i,0,n){
            b[i+1]=a[i]+b[i];
            c[i+1]=max(c[i],a[i]);
        }
        vector<ll>ret;
        while(q--){
            ll k;cin>>k;
            ll idx=upper_bound(ALL(c),k)-c.begin();
            ret.push_back(b[idx-1]);
        }
        rep(i,0,ret.size()){
            cout<<ret[i];
            if(i!=ret.size()-1)cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}