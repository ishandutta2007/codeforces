#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,k,a[N],cnt[105];
int main(){
    scanf("%i %i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        int need=max(0,sum-k),ans=0;
        for(int j=100;j>=1;j--){
            int tmp=cnt[j]*j;
            if(tmp<=need)ans+=cnt[j],need-=tmp;
            else ans+=(need+j-1)/j,need=0;
        }
        printf("%i ",ans);
        cnt[a[i]]++;
    }
    return 0;
}