#include <bits/stdc++.h>
char str[256];
int a[256];
int main(void){
    register int i;
    gets(str);
    for(i=0;str[i];i++)
        a[str[i]]++;
    a[' ']+=256;
    gets(str);
    for(i=0;str[i];i++)
        if(--a[str[i]]<0)
            puts("NO"),exit(0);
    puts("YES");
    return 0;
}