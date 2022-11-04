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
    ll a,b,c;
    ll d=0;
    cin>>a>>b>>c;
    ll dd=min(a/3,min(b/2,c/2));
    a-=dd*3;
    b-=dd*2;
    c-=dd*2;
    d+=dd*7;
    if(a==1)
    {
            d++;
        if(c>=2)
        {
            d+=2;
            if(b>=2)
                d+=2;
            else
                d+=b;
        }
        else if(c<2)
        {
            d+=c;
            if(b)
            d++;
        }
    }
    else if(a==0)
    {
        if(b)
            d++;
        if(c)
            d++;
    }
    else if(a==2)
    {
        d+=2;
        if(b>=2)
            d+=2;
        else
            d+=b;
        if(c>=2)
            d+=2;
        else
            d+=c;
    }
    else if(b==1)
    {
        if(c==0)
            d+=3;
        if(c==1)
            d+=5;
        if(c>=2)
            d+=6;
    }
    else if(b==0)
    {
        if(c>=2)
            d+=3;
        else d+=2;
    }
    else if(c==0)
        d+=4;
    else if(c==1)
        d+=6;
    cout<<d<<endl;
    return 0;
}