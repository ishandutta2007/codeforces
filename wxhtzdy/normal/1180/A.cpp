#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    long long ans=1,tmp=4;
    for(int i=2;i<=n;i++)ans+=tmp,tmp+=4;
    printf("%lld",ans);
    return 0;
}