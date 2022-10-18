#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    cout<<(n+1)/2*((n%2)?-1:1);
}