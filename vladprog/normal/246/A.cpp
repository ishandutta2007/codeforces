#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=2)return printf("-1"), 0;
    for(int i=n;i>=1;i--)printf("%d ",i);
}