#include <bits/stdc++.h>
using namespace std;
int main(){
    int tt;scanf("%i",&tt);
    while(tt--){
        int c1,c2,c3;
        scanf("%i %i %i",&c1,&c2,&c3);
        int a,b,c,d,e;
        scanf("%i %i %i %i %i",&a,&b,&c,&d,&e);
        c1-=a,c2-=b,c3-=c;
        if(c1<0||c2<0||c3<0){
            printf("NO\n");
            continue;
        }
        int mn=min(d,c1);
        d-=mn,c1-=mn;
        mn=min(d,c3);
        d-=mn,c3-=mn;
        mn=min(e,c2);
        e-=mn,c2-=mn;
        mn=min(e,c3);
        e-=mn,c3-=mn;
        if(c1<0||c2<0||c3<0||d>0||e>0)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}