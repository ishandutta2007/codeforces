#include <stdio.h>
#include <string.h>

long long pow(long long v, long long j)
{long long ans=1, i; for(i=1; i<=j; i++) ans*=v; return ans;}

int main()
{
    long long i, j, k, n, v, s1, s2;
    scanf("%I64d", &n);
    for(i=0; i<=11; i++)
    {
        for(j=0;j<(1<<i); j++)
        {
            v=0; s1=s2=0;
            for(k=0; k<i; k++)
            {
                if (!(j&(1<<k))) {v+=4*pow(10, k); s1++;}
                else {v+=7*pow(10, k); s2++;}
            }
            if (s1==s2 && v>=n) {printf("%I64d", v); return 0;}
        }
    }

}