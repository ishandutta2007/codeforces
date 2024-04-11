#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hor;
    int ver;
    int num;
    scanf("%d %d", &hor, &ver);
    while(hor!=0&&ver!=0)
    {
        hor--;
        ver--;
        num++;
    }
    if(num%2==1)
    {
        printf("Akshat");
    }
    else
    {
        printf("Malvika");
    }
    return 0;
}