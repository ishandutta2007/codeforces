#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#define uint long long int
#define N 1000005
using namespace std;
uint bal[N];
uint odp[N];
int main()
{
    ios_base::sync_with_stdio(0);
    uint n, x;
    cin>>n>>x;
    uint mini=N*1000, ind=1;
    for(int i=1; i<=n; i++)
    {
        cin>>bal[i];
    }
    for(int i=x+1; i<=n; i++)
    {
        // cin>>bal[i];
        if(bal[i]<=mini)
        {
            mini=bal[i];
            ind=i;
        }
    }
    for(int i=1; i<=x; i++)
    {
        if(bal[i]<=mini)
        {
            mini=bal[i];
            ind=i;
        }
    }
    uint ruch=0;
    if(x<ind)
    {
        ruch+=x+n-ind;
    }
    else
    {
        ruch+=x-ind;
    }
    ruch+=n*mini;
    if(ind==x)
    {
        mini--;
    }
    for(int i=1; i<=n; i++)
    {
        if(i==ind)
        {
            cout<<ruch<<" ";
        }
        else
        {
            if((i<=x && i>ind)||( ind>=x && (i>ind || i<=x) ) )
            {
                cout<<bal[i]-mini-1<<" ";
            }
            else
            {
                cout<<bal[i]-mini<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}