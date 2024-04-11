#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,coun=1;
    cin>>n;
    n--;
    for(long long i=2;i<n;i++)
    {
        if(__gcd(i,n)==1) coun++;
    }
    cout<<coun;
}