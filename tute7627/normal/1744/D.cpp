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
        ll now=0;
        rep(i,0,n){
            cin>>a[i];
            while(a[i]%2==0){
                a[i]/=2;
                now++;
            }
        }
        vector<ll>v;
        rep(i,1,n+1){
            ll b=i;
            ll cc=0;
            while(b%2==0){
                b/=2;
                cc++;
            }
            v.push_back(cc);

        }
        ll ret=0;
        sort(ALLR(v));
        for(auto z:v){
            if(now<n){
                now+=z;
                ret++;
            }
        }
        if(now<n)cout<<-1<<endl;
        else cout<<ret<<endl;
    }
}