#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
typedef long double lb;
struct node{
    ll x,num;
}a[N];
ll ans[N];
bool kmp(node kk,node kkk){return kk.x>kkk.x;}
int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++)scanf("%lld",&a[i].x),a[i].num=i;
        sort(a+1,a+n+1,kmp);
        long long res=0;
        for(ll i=1;i<=n;i+=2){
            ans[a[i].num]=i/2+1,res+=a[i].x*(i/2+1);
            if(i!=n)ans[a[i+1].num]=-(i/2+1),res+=a[i+1].x*(i/2+1);
        }
        printf("%lld\n0 ",res*2ll);
        for(ll i=1;i<=n;i++)printf("%lld ",ans[i]);
        puts("");
    }
    return  0;
}