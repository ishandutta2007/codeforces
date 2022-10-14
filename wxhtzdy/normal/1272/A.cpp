#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int a,b,c;scanf("%i%i%i",&a,&b,&c);
        long long ans=1e18;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                for(int k=-1;k<=1;k++){
                    int na=a+i,nb=b+j,nc=c+k;
                    ans=min(ans,(long long)abs(na-nb)+abs(nb-nc)+abs(na-nc));
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}