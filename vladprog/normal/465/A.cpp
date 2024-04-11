#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i\n",&n);
    for(int i=1;i<=n;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='0')
        {
            printf("%i\n",i);
            return(0);
        }
    }
    printf("%i\n",n);
}