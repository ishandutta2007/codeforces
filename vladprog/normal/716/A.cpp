#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,c;
    scanf("%i%i",&n,&c);
    int k=0,p=0;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%i",&t);
        if(t-p>c)
            k=1;
        else
            k++;
        p=t;
    }
    printf("%i\n",k);
}