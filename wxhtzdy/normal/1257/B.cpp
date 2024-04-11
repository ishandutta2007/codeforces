#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int x,y;scanf("%i %i",&x,&y);
        if(x>=4)printf("YES\n");
        else{
            if(x==1){
                if(y==1)printf("YES\n");
                else printf("NO\n");
            }else{
                if(y<=3)printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}