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
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>a(n);
        rep(i,0,n)cin>>a[i];
        string s;cin>>s;
        bool sw=true;
        rep(i,0,n)rep(j,i+1,n){
            if(a[i]==a[j]&&s[i]!=s[j])sw=false;
        }
        if(sw)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}