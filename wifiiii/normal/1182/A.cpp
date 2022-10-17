#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    if(n%2) cout<<0<<endl;
    else cout<<(1ll<<(n/2))<<endl;
}