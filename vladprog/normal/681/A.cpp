#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char s[11];
        int a,b;
        scanf("%s%i%i",s,&a,&b);
        if(a>=2400&&b>a)
            return printf("YES"),0;
    }
    printf("NO");
}