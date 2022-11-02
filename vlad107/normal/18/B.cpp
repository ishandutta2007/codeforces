#include <stdio.h>

long long d,m,l;
int n;

inline long long next(long long x){
    long long y=x/d;
    if (x%d>0)y++;
    return d*y;
}

int main(){
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%I64d%I64d%I64d%I64d",&n,&d,&m,&l);
    for (int i=0;i<n;i++){
        long long ss=i*1LL*m+l+1,
                      ff=(i+1)*1LL*m-1;
//      printf("%d %d",ss,ff);
        long long x=ff/d-(ss-1)/d;
//      printf("%d %d %d\n",ss,ff,x);
        if (x){
            printf("%I64d\n",next(ss));
            return 0;
        }
    }
    printf("%I64d\n",next((n-1)*1LL*m+l+1));
}