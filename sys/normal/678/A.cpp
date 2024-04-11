#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    if(x%n==0) printf("%d",x+n);
    else
        printf("%d",(long long)ceil(x/(double)n)*n);
    return 0;
}