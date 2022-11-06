#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    int n, i, j, i1;
    scanf("%d", &n);
    if (n<18)
    {
        for(i=0; i<10; i++)
            for(j=0; j<10; j++)
                if (i*4+j*7==n)
                {
                    for(i1=0; i1<i; i1++) putchar('4');
                    for(i1=0; i1<j; i1++) putchar('7');
                    return 0;
                }
        printf("-1"); return 0;
    }
    switch(n%7)
    {
    case(0):{j=n/7; i=0; break;}
    case(1):{j=(n-8)/7; i=2; break;}
    case(2):{j=(n-16)/7; i=4; break;}
    case(3):{j=(n-24)/7; i=6; break;}
    case(4):{j=(n-4)/7; i=1; break;}
    case(5):{j=(n-12)/7; i=3; break;}
    case(6):{j=(n-20)/7; i=5; break;}
    }
    for(i1=0; i1<i; i1++) putchar('4');
    for(i1=0; i1<j; i1++) putchar('7');
}