#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    if(n==1)
    {
        int a;
        scanf("%i",&a);
        switch(a)
        {
            case 15:printf("DOWN\n");break;
            case 0:printf("UP\n");break;
            default:printf("-1\n");
        }
        return 0;
    }
    int b;
    for(int i=1;i<n;i++)
        scanf("%i",&b);
    int a;
    scanf("%i",&a);
    switch(a)
    {
        case 15:printf("DOWN\n");break;
        case 0:printf("UP\n");break;
        default:printf((a>b)?"UP\n":"DOWN\n");
    }
}