#include <stdio.h>
#include <string.h>

char c[100005];

int main()
{
    int i, j, cur, f, sum, ln;
    scanf("%s", &c);
    ln=strlen(c);
    if (ln==1) {printf("0"); return 0;}
    cur=0;
    for(i=0; i<ln; i++) cur+=(int)(c[i]-'0');
    for(f=1, sum=cur; sum>=10; f++)
    {
        cur=sum;
        sum=0;
        while(cur) {sum+=cur%10; cur/=10;}
    }
    printf("%d", f);
}