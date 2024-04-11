#include<bits/stdc++.h>

#define mp make_pair

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int sx=0,sy=0;
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sx+=x;
        sy+=y;
        if((x+y)%2)
            ok=true;
    }
    if((!(sx%2))&&(!(sy%2)))
        printf("0");
    else if(sx%2&&sy%2&&ok)
        printf("1");
    else
        printf("-1");
}