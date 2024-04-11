#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[N];
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        int tot=0,pd=1,al=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=2;i<n;i++){
            if(a[i]!=1)pd=0;
            tot+=a[i];
            al+=a[i]%2==1;
        }
        if(pd||(n==3&&al==1)){
            puts("-1");
            continue;
        }
        printf("%lld\n",al+((tot-al)>>1));
    }
    return  0;
}