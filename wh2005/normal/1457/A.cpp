#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n,m,r,c;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&r,&c);
        printf("%lld\n",max(max(r-1+c-1,r-1+m-c),max(n-r+c-1,n-r+m-c)));
    }
    return 0;
}