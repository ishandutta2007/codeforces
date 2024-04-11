#include<bits/stdc++.h>

using namespace std;

const int a1=1234567;
const int a2=123456;
const int a3=1234;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;a1*i<=n;i++)
        for(int j=0;a1*i+a2*j<=n;j++)
            if((n-a1*i-a2*j)%a3==0)
                return printf("YES"),0;
    printf("NO");
}