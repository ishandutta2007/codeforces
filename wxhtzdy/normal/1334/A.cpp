#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int x=0,y=0;
        bool ok=1;
        for(int i=0;i<n;i++){
            int a,b;scanf("%i %i",&a,&b);
            int dx=a-x,dy=b-y;
            if(dx<dy||dx<0||dy<0)ok=0;
            x=a,y=b;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}