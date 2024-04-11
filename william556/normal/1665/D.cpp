#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll val=1000000000;
void solve(){
    long long a=1;
    long long x=0;
    for(int i=0;i<30;i++){
        cout<<"? "<<a<<' '<<a+(1ll<<i+1)<<endl;
        long long c;
        cin>>c;
        if(c%(1ll<<i+1)!=0)a+=1ll<<i;
        else x|=1ll<<i;
    }
    cout<<"! "<<x<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}