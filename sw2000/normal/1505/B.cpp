#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;cin>>a;
    while(a>=10)
    {
        int tmp=0;
        while(a)
        {
            tmp+=a%10;
            a/=10;
        }
        a=tmp;
    }
    cout<<a;
    return 0;
}