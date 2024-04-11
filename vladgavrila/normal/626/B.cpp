#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define maxn 210

int n, m;
string s;
int d[maxn][maxn][maxn];
int nbb[2000];

int main()
{
    cin>>n;
    cin>>s;
    int sol=0;
    for(int i=0; i<n; ++i)
        ++nbb[s[i]];

    int nr = nbb['R'];
    int ng = nbb['G'];
    int nb = nbb['B'];

    d[nr+ng+nb][nb][ng]=1;

    for(int i=n; i>1; --i)
    {
        for(int b=0; b<=i; ++b)
            for(int g=0; g+b<=i; ++g)
            {
                if(d[i][b][g]==0)
                    continue;
                int r=i-b-g;
                if(r>0 && g>0)
                    d[i-1][b+1][g-1]=1;
                if(r>0 && b>0)
                    d[i-1][b-1][g+1]=1;
                if(g>0 && b>0)
                    d[i-1][b-1][g-1]=1;

                if(r>1)
                    d[i-1][b][g]=1;
                if(g>1)
                    d[i-1][b][g-1]=1;
                if(b>1)
                    d[i-1][b-1][g]=1;
            }
    }

    if(d[1][1][0])
        cout<<"B";
    if(d[1][0][1])
        cout<<"G";
    if(d[1][0][0])
        cout<<"R";
    cout<<"\n";

    return 0;
}