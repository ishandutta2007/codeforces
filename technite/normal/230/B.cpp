#include <bits/stdc++.h>
#include <math.h>
int main(){
    
     int prime[1000000]={0};
    
    
    prime[1]=1;
    for(int i=2;i*i<=1000000;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=1000000;j+=i){
                prime[j]=1;
            }
        }
    }
    
    int t;
    long long int n,j;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%lld",&n);
        double m = n;
        j=sqrt(m);
        if(j*j==n && prime[j]==0)
            printf("YES\n");
        else
            printf("NO\n");
    
    }
}