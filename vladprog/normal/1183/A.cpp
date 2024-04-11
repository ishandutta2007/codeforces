#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int sum(int x)
{
    int res=0;
    while(x)
        res+=x%10,x/=10;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    while(sum(a)%4!=0)
        a++;
    cout<<a;
}