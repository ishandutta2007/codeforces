#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const ll INF=1e18;
int n;
ll a[N],ans=INF;
bool ok(ll c){
    ll tmp=c;
    for(int i=0;i<n;i++){
        if(tmp>=5e17)return false;
        tmp*=c;
    }
    return true;
}
void tryc(ll c){
    ll res=0;
    for(ll i=0;i<n;i++)res+=abs(a[i]-pow(c,i));
    ans=min(ans,res);
}
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);
    for(ll c=1;c<=100000;c++){
        if(!ok(c))break;
        //cerr << c << endl;
        tryc(c);
    }
    printf("%lld",ans);
    return 0;
}