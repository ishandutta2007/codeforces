#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        n<<=1;
        long long now=n;
        long long sum1=1;
        while(n%2==0)sum1<<=1,n>>=1;
        long long sum2=now/sum1;
        if(sum2>=sum1+1&&sum1>1){
            printf("%lld\n",sum1);
        }
        else{
            if(sum1>=sum2+1&&sum2>1)printf("%lld\n",sum2);
            else puts("-1");
        }
    }
    return  0;
}