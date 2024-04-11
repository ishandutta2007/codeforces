#include<bits/stdc++.h>
using namespace std;

int t;
long long n;
vector<int> vec(25);
vector<int> sum(25);
long long f[22];
int main(){
    scanf("%d",&t);
    f[0]=1;
    for (int i=1;i<22;++i){
        f[i]=f[i-1]*i;
    }
    while(t--){
        scanf("%lld",&n);
        for (int i=0;i<25;++i){
            vec[i]=0;
        }
        int j=1;
        while (n){
            j++;
            vec[n%j]++;
            n/=j;
        }
        sum=vec;
        for (int i=1;i<25;++i){
            sum[i]+=sum[i-1];
        }
        long long ans=1,tot=1;
        for (int i=2;i<=j;++i){
            ans*=(sum[i-1]-i+2);
        }
        for (int i=0;i<j;++i){
            ans/=f[vec[i]];
        }
        if (vec[0]){
            vec[0]--;
            for (int i=2;i<j;++i){
                tot*=(sum[i-1]-i+1);
            }
            for (int i=0;i<j;++i){
                tot/=f[vec[i]];
            }
        }
        else{
            tot=0;
        }
        ans-=tot;
        printf("%lld\n",ans-1);
    }
}