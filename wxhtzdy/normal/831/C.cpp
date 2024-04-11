#include <bits/stdc++.h>
using namespace std;
const int N=2050;
int n,k,a[N],b[N],sum[N];
int main(){
    scanf("%i %i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=k;i++)scanf("%i",&b[i]);
    set<int> s;
    for(int i=0;i<=n;i++){
        int st=b[1]-sum[i];
        map<int,int> cnt;
        for(int j=1;j<=n;j++)st+=a[j],cnt[st]++;
        bool ok=1;
        for(int j=1;j<=k;j++)if(cnt[b[j]]==0)ok=0;
        if(ok)s.insert(b[1]-sum[i]);
    }
    printf("%i",(int)s.size());
    return 0;
}