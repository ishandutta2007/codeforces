#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,a,b;
    scanf("%i%i%i%i",&x,&y,&a,&b);
    int n=0;
    char c[8];
    string s;
    for(int i=a;i<=x;i++)
        for(int j=b;j<=min(y,i-1);j++)
        {
            n++;
            sprintf(c,"%i %i\n",i,j);
            s+=c;
        }
    printf("%i\n%s",n,&s[0]);
}