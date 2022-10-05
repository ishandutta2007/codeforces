#include<bits/stdc++.h>
using namespace std;
char a[1000],b[1000],c[1000];
int s,d;
int main()
{
    scanf("%s%d",a,&s); 
    d=strlen(a); 
    while(s--){
        scanf("%s",b);
        if(!strncmp(a,b,d)){
            if(!c[0]) strcpy(c,b);
            if(strcmp(b,c)<=0) strcpy(c,b);
        }
    }if(c[0]) printf("%s",c); 
    else printf("%s",a);
    return 0;
}