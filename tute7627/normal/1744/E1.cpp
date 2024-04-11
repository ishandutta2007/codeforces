#include<bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa <<" "<<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
using ll=long long;
template<typename T1,typename T2>
bool chmin(T1 &a,T2 b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}
template<typename T1,typename T2>
bool chmax(T1 &a,T2 b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

vector<ll>divisor(ll n){
    vector<ll>ret;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            ret.push_back(n/i);
        }
    }
    return ret;
}
int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        ll p=-1,q=-1;
        auto da=divisor(a);
        auto db=divisor(b);
        for(auto dx1:da)for(auto dx2:db){
            ll dx=dx1*dx2;
            ll dy=(a/dx1)*(b/dx2);
            ll x=(a+dx)/dx*dx;
            ll y=(b+dy)/dy*dy;
            if(x<=c&&y<=d)p=x,q=y;
        }
        cout<<p spa q<<endl;
    }
}