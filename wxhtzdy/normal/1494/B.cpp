#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,u,r,d,l;scanf("%i%i%i%i%i",&n,&u,&r,&d,&l);
        for(int i=0;i<16;i++){
            int na=u,nb=r,nc=d,nd=l;
            if(i&1)na--,nd--;
            if(i&2)na--,nb--;
            if(i&4)nc--,nd--;
            if(i&8)nc--,nb--;
            if(na>=0&&nb>=0&&nc>=0&&nd>=0&&na<=n-2&&nb<=n-2&&nc<=n-2&&nd<=n-2){
                printf("YES\n");
                break;
            }
            if(i==15)printf("NO\n");
        }
    }
    return 0;
}