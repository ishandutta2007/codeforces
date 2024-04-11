#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N];
map<int,int> cnt;
int main(){
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    long long ans=0;
    for(int i=0;i<n;i++){
        long long k=1;
        for(long long j=1;j<40;j++){
            k*=2;
            if(k>2e9)break;
            if(a[i]>=k)continue;
            ans+=cnt[k-a[i]];
        }
        cnt[a[i]]++;
    }
    printf("%lld",ans);
    return 0;
}