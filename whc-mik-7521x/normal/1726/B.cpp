#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n&1){
            n--;
            m-=n;
            if(m>=1){
                puts("YES");
                for(int i=1;i<=n;i++)printf("1 ");
                printf("%d\n",m);
            }
            else puts("NO");
        }
        else{
            n-=2;
            m-=n;
            if(m>1&&(!(m&1))){
                puts("YES");
                for(int i=1;i<=n;i++)printf("1 ");
                printf("%d %d\n",m>>1,m>>1);
            }
            else puts("NO");
        }
    }
    return 0;
}