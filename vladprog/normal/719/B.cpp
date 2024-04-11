#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i\n",&n);
    bool b[n],r[n];
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='b')
        {
            b[i]=true;
            r[i]=false;
        }
        else
        {
            r[i]=true;
            b[i]=false;
        }
    }

    int n1,n2;

    #define a0 b
    #define a1 r
    #define k k1

    int k;
    n1=0;
    for(int i=0;i<n;i+=2)
        if(a0[i])n1++;
    n2=0;
    for(int i=1;i<n;i+=2)
        if(a1[i])n2++;
    k=max(n1,n2);

    #define a0 r
    #define a1 b
    #define k k2

    int k;
    n1=0;
    for(int i=0;i<n;i+=2)
        if(a0[i])n1++;
    n2=0;
    for(int i=1;i<n;i+=2)
        if(a1[i])n2++;
    k=max(n1,n2);

    printf("%i\n",min(k1,k2));
}