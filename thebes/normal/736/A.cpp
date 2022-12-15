#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[10005], n, tot, ans;

int main(){
    scanf("%lld",&n);
    a[1] = 1; n--;
    while(tot<=n){
        ans++; tot += a[ans];
        a[ans+1] = a[ans-1]+a[ans];
        if(tot>n){
            printf("%d\n",ans-1);
            return 0;
        }
    }
}