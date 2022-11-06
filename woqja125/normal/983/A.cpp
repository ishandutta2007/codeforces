#include<cstdio>
long long gcd(long long a, long long b){
    return b?gcd(b, a%b):a;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        long long p, q, b, g;
        scanf("%lld%lld%lld", &p, &q, &b);
        g = gcd(p, q);
        p/=g; q/=g;
        g = gcd(q, b);
        for(int j=1; j<=100 && q > 1; j++){
            if(q%g == 0) q/=g;
            else{
                g = gcd(g, q);
                if(g==1) break;
                q/=g;
            }
        }
        if(q==1) printf("Finite\n");
        else printf("Infinite\n");
    }
}