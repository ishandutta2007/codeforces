#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int a,b,n;scanf("%i %i %i",&a,&b,&n);
        if(n%3==0)printf("%i\n",a);
        else if(n%3==1)printf("%i\n",b);
        else printf("%i\n",a^b);
    }
    return 0;
}