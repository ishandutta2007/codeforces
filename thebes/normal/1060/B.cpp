#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ans;
ll S(ll n){
    ll res = 0;
    while(n){
        res += n%10;
        n /= 10;
    }
    return res;
}
int main(){
    scanf("%lld",&n);
    if(n<=9) printf("%lld\n",n);
    else{
        ans = 1LL;
        while(ans*10<=n){
            ans *= 10;
        }
        printf("%lld\n",S(ans-1)+S(n-ans+1));
    }
    return 0;
}