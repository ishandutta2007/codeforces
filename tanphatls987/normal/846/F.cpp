#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N=1e6+10;


int n,last[N];
int main(){
    scanf("%d",&n);
    ll ans=0,sum=0;
    for(int i=1;i<=n;i++){
        int val;
        scanf("%d",&val);
        if (last[val]) sum-=last[val];
        sum+=i;
        last[val]=i;
        ans+=sum;
    }
    printf("%.9f",(2*ans-n+.0)/(1LL*n*n));
}