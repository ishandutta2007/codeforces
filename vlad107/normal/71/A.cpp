#include <stdio.h>
#include <memory.h>

int n;

int main(){
    scanf("%d\n",&n);    
    for (int i=0;i<n;i++){
        char s[100500];
        gets(s);
        int x=strlen(s);
        if (x<=10)
            puts(s);
        else printf("%c%d%c\n",s[0],x-2,s[x-1]);
    }
}