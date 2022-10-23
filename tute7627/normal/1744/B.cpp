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
        ll n,q;cin>>n>>q;
        vector<ll>a(2),b(2);
        rep(i,0,n){
            ll x;cin>>x;
            a[x%2]++;
            b[x%2]+=x;
        }
        while(q--){
            ll p,x;cin>>p>>x;

            ll num=a[p];a[p]=0;
            ll sum=b[p];
            b[p]=0;
            b[(x+p)%2]+=num*x+sum;
            a[(x+p)%2]+=num;
            cout<<b[0]+b[1]<<endl;
        }
    }
}