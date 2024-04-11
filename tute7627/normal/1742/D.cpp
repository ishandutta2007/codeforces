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
    vector<pair<int,int>>p;
    rep(i,1,1001)rep(j,i,1001){
        if(gcd(i,j)==1)p.emplace_back(i,j);
    }
    while(t--) {
        ll n;cin>>n;
        vector<ll>a(n);
        rep(i,0,n)cin>>a[i];
        vector<ll>v(1001,-1e9);
        rep(i,0,n)v[a[i]]=i+1;
        ll ret=-1;
        for(auto z:p){
            chmax(ret,v[z.first]+v[z.second]);
        }
        cout<<ret<<endl;
    }
    return 0;
}