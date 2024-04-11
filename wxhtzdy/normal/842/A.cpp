#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    long long l,r,x,y,k;
    scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&y,&k);
    for(long long i=x;i<=y;i++){
        if(i*k>=l&&i*k<=r){printf("YES");return 0;}
    }
    printf("NO");
}