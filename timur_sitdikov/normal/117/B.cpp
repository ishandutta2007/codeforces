#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   
   
    char s[11]; s[9]=0;
    long long a, b, c, mod, i, d, j, lim;
    scanf("%lld %lld %lld", &a, &b, &mod);
    if (b>=mod-1) {printf("2"); return 0;}
    lim=(a<mod-1? a: mod-1);
    d=1000000000%mod;
    for(i=0; i<=lim; i++)
    {
        c=(i*d)%mod;
        if (c && b<mod-c)
        {
            for(j=0; j<9; j++) s[j]='0';
            for(j=8; i>0; j--) {s[j]=i%10+'0'; i/=10;}
            printf("1 %s", s);
            return 0;
        }
    }
    printf("2");
}