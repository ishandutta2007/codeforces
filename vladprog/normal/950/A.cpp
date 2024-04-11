#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l,r,a;
    cin>>l>>r>>a;
    cout<<min({(l+r+a)/2,l+a,r+a})*2;
}