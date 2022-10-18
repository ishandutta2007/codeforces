#include<bits/stdc++.h>

using namespace std;

int main()
{
    int d1,d2,d3;
    scanf("%d%d%d",&d1,&d2,&d3);
    printf("%d",min(d1+d2+d3,2*min(d1+d2,min(d1+d3,d2+d3))));
}