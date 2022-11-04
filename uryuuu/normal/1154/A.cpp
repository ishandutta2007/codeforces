#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#define ll long long
#define N 500005
#define mod 1000000007
ll inf=1e18;
using namespace std;
int main()
{
    ll a,b,c,d,s;
    cin>>a>>b>>c>>d;
    s=(a+b+c+d)/3;
    if(s==a)
        cout<<s-b<<' '<<s-c<<' '<<s-d<<endl;
    else if(s==b)
        cout<<s-a<<' '<<s-c<<' '<<s-d<<endl;
    else if(s==c)
        cout<<s-a<<' '<<s-b<<' '<<s-d<<endl;
    else if(s==d)
        cout<<s-a<<' '<<s-c<<' '<<s-b<<endl;
    return 0;
}