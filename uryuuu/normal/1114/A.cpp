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
int inf=0x3f3f3f3f;
using namespace std;

int main()
{
    int x,y,z,a,b,c;
    while(cin>>x>>y>>z>>a>>b>>c)
    {
    int f=0;
    a-=x;
    if(a<0)
        f=1;
    int q=a+b;
    q-=y;
    if(q<0)
        f=1;
    if(q+c-z<0)
        f=1;
    if(f)
        cout<<"NO";
    else
        cout<<"YES";
        cout<<endl;
    }
    return 0;
}