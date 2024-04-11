#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d%*c",&n);
    int k=0;
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='0')
            printf("%d",k),k=0;
        else
            k++;
    }
    printf("%d",k);
}