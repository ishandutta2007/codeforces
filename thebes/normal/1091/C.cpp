#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, i;
vector<ll> ans;

int main(){
    scanf("%lld",&n);
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            ll len = n/i;
            ans.push_back(len+len*(len-1)/2*i);
            if(i*i!=n){
                ll len2 = i;
                ans.push_back(len2+len2*(len2-1)/2*n/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto v : ans)
        printf("%lld ",v);
    printf("\n");
    return 0;
}