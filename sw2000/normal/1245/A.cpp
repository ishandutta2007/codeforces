#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)==1)
        {
            puts("Finite");
        }
        else
            puts("Infinite");
    }
    return 0;
}