#include <cstdio>
#include <iostream>

using namespace std;

#define maxn 1010

int n, m, nh, nt, ncc;
int sol, rez, ch;
string v;

int main()
{
  //  freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    cin>>n;
    cin>>v;
    for(int i=0; i<n; ++i)
    {
        if(v[i]=='H')
            ++nh;
        else
            ++nt;
    }

    sol=n+1;

    for(int i=0; i<n; ++i)
    {
        rez=0;
        for(int pz=i, j=0; j<n; ++j, pz=(pz+1)%n)
        {
            if(j>=nh && v[pz]=='H')
                ++rez;
        }
        sol=min(sol, rez);
    }

    cout<<sol<<"\n";

    return 0;
}