#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
ll a,b,x;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&x);
        if(a>b)swap(a,b);
        bool pd=0;
        while(a){
            ll ch=b-a;
            ll now=b-(ch/a+1)*a;
            if(x<=b&&x>=now){
                if((b-x)%a==0){
                    pd=1;
                    break;
                }
            }
            b=a;
            a=now;
        }
        puts(pd?"Yes":"No");
    }
    return  0;
}