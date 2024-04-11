#include<bits/stdc++.h>

using namespace std;

int sc(int p,int t)
{
    return max(3*p/10,p-p/250*t);
}

int main()
{
    int a,b,c,d;
    scanf("%i%i%i%i",&a,&b,&c,&d);
    int m=sc(a,c),v=sc(b,d);
    printf((m==v)?"Tie":((m>v)?"Misha":"Vasya"));
}