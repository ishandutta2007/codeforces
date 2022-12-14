#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<ll>vi;
const int N=2e5+10,M=26;
const int mod=1e7+7;
 
pair<ll,ll>a[N];
void o(__int128 a){
    if(a>9)o(a/10);
    cout<<(char)(a%10+'0');
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int n;cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i].se>>a[i].fi;
        sum+=a[i].se;
    }
    sort(a,a+n);
    __int128 ans=0;
    ll buy=0;
    for(int i=0;i<n;i++){
        if(buy>=a[i].fi){
            ll add=min(sum-buy,a[i].se);
            ans+=add;
            buy+=add;
        }
        else{
            ll add=min(sum-buy,a[i].fi-buy);
            ans+=add*2;
            buy+=add;
            i--;
        }
        if(buy==sum)break;
    }
    o(ans);
}