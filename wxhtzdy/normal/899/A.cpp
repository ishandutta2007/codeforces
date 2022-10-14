#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,a[N];
int main(){
    scanf("%i",&n);
    int cnt[2]={0,0};
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),cnt[a[i]-1]++;
    int ans=min(cnt[0],cnt[1]);
    ans+=(cnt[0]-ans)/3;
    printf("%i",ans);
    return 0;
}