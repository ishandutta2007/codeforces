#include<bits/stdc++.h>

using namespace std;

int main()
{
    int y,k,n;
    scanf("%i%i%i",&y,&k,&n);
    bool ok=false;
    for(int i=k;i<=n;i+=k)
        if(i>y)
        {
            printf("%i ",i-y);
            ok=true;
        }
    if(!ok)
        printf("-1");
}