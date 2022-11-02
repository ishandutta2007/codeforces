#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e3+9;
int T,n,a[N],sum[N];


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sum[0]=0;
        for(int i=1;i<=n;i++) sum[i]=0;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
        int flag=0;
        for(int i=1;i<=n;i++)
            if(sum[i]==(sum[n]^sum[i])) flag=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if((sum[i]==(sum[j]^sum[i]))&&(sum[i]==(sum[n]^sum[j]))) flag=1;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}