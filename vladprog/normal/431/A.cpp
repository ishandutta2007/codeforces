#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[4];
    for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
    scanf("%*c");
    int s=0;
    while(true)
    {
        char c;
        if(scanf("%c",&c)==EOF||c=='\n')
            break;
        s+=a[c-'1'];
    }
    printf("%d",s);
}