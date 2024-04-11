#include <bits/stdc++.h>
using namespace std;
const int N=10000050;
const int inf=1e9;
int sum[N],mn[N];
int main(){
    for(int i=0;i<N;i++)mn[i]=inf;
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            if(sum[j]<=N)sum[j]+=i;
        }
    }
    for(int i=1;i<N;i++){
        if(sum[i]<N){
            mn[sum[i]]=min(mn[sum[i]],i);
        }
    }
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        if(mn[n]==inf)printf("-1\n");
        else printf("%i\n",mn[n]);
    }
    return 0;
}