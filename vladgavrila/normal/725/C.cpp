#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int n, m, p2;
long long nr;
string s;
char sol[2][26];
int f[255];

int main()
{
    n=27;
    cin>>s;
    for(int i=0; i<n; ++i)
    {
        int poz = i+1;
        if(f[s[i]]!=0)
        {
            if(poz-1==f[s[i]])
            {
                cout<<"Impossible\n";
                return 0;
            }
            p2=poz;
        }
        else
            f[s[i]]=poz;
    }

    int crp=f[s[p2-1]];
    int lg=p2-crp-1;

    int x=0, y=12-lg/2;
    int py=1;
    for(int i=crp; i<p2; ++i)
    {
        sol[x][y]=s[i-1];
        y+=py;
        if(x==0 && y==13)
        {
            x=1;
            y=12;
            py=-1;
        }
    }

    x=0;
    y=12-lg/2-1;
    py=-1;
    if(y==-1)
    {
        x=1;
        y=0;
        py=1;
    }
    for(int i=p2+1; i<=n; ++i)
    {
        sol[x][y]=s[i-1];
        y+=py;
        if(x==0 && y==-1)
        {
            x=1;
            y=0;
            py=1;
        }
    }
    for(int i=1; i<crp; ++i)
    {
        sol[x][y]=s[i-1];
        y+=py;
        if(x==0 && y==-1)
        {
            x=1;
            y=0;
            py=1;
        }
    }

    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<13; ++j)
            cout<<sol[i][j];
        cout<<"\n";
    }

    return 0;
}