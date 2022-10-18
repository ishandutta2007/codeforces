#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf((abs(a-b)<=1&&a+b>=1)?"YES":"NO");
}