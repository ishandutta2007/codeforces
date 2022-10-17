#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n;
int main()
{
    while(cin>>n)
    {
        int a=0,ra=0,rb=0,b=0;
        while(n--)
        {
            int t,x,y;
            cin>>t>>x>>y;
            if(t==1)  {a+=10;ra+=x;}
            else {b+=10;rb+=x;}
        }
        if(2*ra>=a) puts("LIVE");
        else puts("DEAD");
        if(2*rb>=b) puts("LIVE");
        else puts("DEAD");
    }
    return 0;
}