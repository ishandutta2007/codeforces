#include <bits/stdc++.h>
using namespace std;
const int N=12;
map<int,int> cnt[N];
int main(){
    int n,k;scanf("%i %i",&n,&k);
    int a[n];
    long long ans=0;
    for(int i=0;i<n;i++){
        scanf("%i",&a[i]);
        int b=a[i],c=0;
        while(b)b/=10,c++;
        cnt[c][a[i]%k]++;
        long long tmp=a[i];
        for(int j=0;j<c;j++)tmp*=10,tmp%=k;
        tmp+=a[i];
        if(tmp%k==0)ans--;
    }
    for(int i=0;i<n;i++){
        long long r=a[i];
        for(int j=1;j<=10;j++){
            r*=10;
            r%=k;
            long long diff=(k-r)%k;
            ans+=cnt[j][diff];
        }
    }
    printf("%lld",ans);
    return 0;
}