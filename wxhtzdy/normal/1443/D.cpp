#include <bits/stdc++.h>
using namespace std;
const int N=30050;
int n,a[N];
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        scanf("%i",&n);
        long long b[n+1];
        b[0]=0;
        for(int i=1;i<=n;i++)scanf("%i",&a[i]),b[i]=0;
        for(int i=2;i<=n;i++){
            int diff=abs(a[i]-a[i-1]);
            if(a[i-1]>a[i]){
                b[i]+=diff;
                b[1]-=diff;
            }else{
                b[i]-=diff;
            }
        }
        bool ok=true;
        for(int i=1;i<=n;i++){
            b[i]+=b[i-1];
            if((a[i]+b[i])<0)ok=false;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}