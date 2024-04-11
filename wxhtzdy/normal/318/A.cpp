#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    --k;
    if(n%2==0){
        if(k<n/2)printf("%lld",k*2+1);
        else k-=n/2,printf("%lld",k*2+2);
    }else{
        if(k<(n+1)/2)printf("%lld",k*2+1);
        else k-=(n+1)/2,printf("%lld",k*2+2);
    }
}