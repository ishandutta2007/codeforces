#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int k=0;
    for(int a=0;a<=min(n,m);a++)
        for(int b=0;b<=min(n,m);b++)
            if(a*a+b==n&&a+b*b==m)
                k++;
    cout<<k;
}