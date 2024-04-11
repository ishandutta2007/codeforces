#include<bits/stdc++.h>
using namespace std;
int t,p,pp;
double x,xx;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lf%d%lf%d",&x,&p,&xx,&pp);
        while(x>=10)x/=10,p++;
        while(xx>=10)xx/=10,pp++;
        if(p==pp){
            puts(x>xx?">":(x==xx?"=":"<"));
        }
        else puts(p>pp?">":"<");
    }
    return  0;
}