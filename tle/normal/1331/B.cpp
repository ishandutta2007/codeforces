#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    for(int i=2;i<x;++i) if(x%i==0)
    {
        cout<<i<<x/i;
        break;
    }
}