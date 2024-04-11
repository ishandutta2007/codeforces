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
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int main()
{
    int a,b,n=0;
    cin>>a>>b;
    if(b%a)
    {
        cout<<-1<<endl;
        return 0;
    }
    int d=b/a;
    while(d%3==0)
    {
        d/=3;
        n++;
    }
    while(d%2==0)
    {
        d/=2;
        n++;
    }
    if(d!=1&&d)
        cout<<-1<<endl;
    else
        cout<<n<<endl;
    return 0;
}