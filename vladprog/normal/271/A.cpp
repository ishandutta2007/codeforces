#include<bits/stdc++.h>

using namespace std;

int main()
{
    int y;
    scanf("%d",&y);
    while(true)
    {
        y++;
        int a=y/1000,b=y/100%10,c=y/10%10,d=y%10;
        if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
            return printf("%d",y),0;
    }
}