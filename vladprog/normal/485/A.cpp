#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(a>b) swap(a,b);
    return (a==0)?b:gcd(b%a,a);
}

int main()
{
    int a,m;
    scanf("%i%i",&a,&m);
    m=m/gcd(a,m);
    while (!(m%2)) m/=2;
    printf((m==1)?"Yes\n":"No\n");
}