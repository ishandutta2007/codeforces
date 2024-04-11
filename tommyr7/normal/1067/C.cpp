#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    int nowx=0,nowy=0;
    for (int i=1;i<=n;i++)
    {
        printf("%d %d\n",nowx,nowy);
        if (i%3==1) nowy+=2;
        else if (i%3==2) nowx+=1,nowy-=1;
        else nowx+=1,nowy-=1;
    }
    return 0;
}