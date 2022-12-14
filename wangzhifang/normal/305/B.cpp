#include <cstdio>
using namespace std;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
int main(){
    long long p,q,tmp,x;
    int n;
    scanf("%I64d%I64d%d",&p,&q,&n);
    for(int i=0; ++i<=n; p/=tmp,q/=tmp){
        scanf("%I64d",&x);
        if(p/q<x){
            puts("NO");
            return 0;
        }
        tmp=q;
        q=p-q*x;
        if(q<=0&&i!=n){
        	puts("NO");
            return 0;
        }
        p=tmp;
        tmp=gcd(p,q);
    }
    if(q>0)
        printf("NO");
    else
        printf("YES");
    return 0;
}