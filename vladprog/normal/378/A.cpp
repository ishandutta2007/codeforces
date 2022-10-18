#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int x=0,y=0,z=0;
    for(int i=1;i<=6;i++)
        if(abs(i-a)<abs(i-b))
            x++;
        else if(abs(i-a)==abs(i-b))
            y++;
        else
            z++;
    printf("%d %d %d",x,y,z);
}