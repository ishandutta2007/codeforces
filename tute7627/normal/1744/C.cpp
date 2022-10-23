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
        char c;cin>>c;
        string s;cin>>s;
        s+=s;
        ll cnt=0;
        ll mx=0;
        rrep(i,0,2*n){
            if(s[i]=='g')cnt=0;
            else cnt++;
            if(s[i]==c)chmax(mx,cnt);
        }
        cout<<mx<<endl;
    }
}