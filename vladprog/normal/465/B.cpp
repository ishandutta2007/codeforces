#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int k=-1,s=-1;
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%i",&c);
        if(c)
        {
            if((i-k)==1)
                s++;
            else
                s+=2;
            k=i;
        }
    }
    printf("%i\n",max(s,0));
}