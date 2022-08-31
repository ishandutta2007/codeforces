#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int w[105];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, l, d;
    cin>>n>>d>>l;
    int mini=0;
    mini+=(n+1)/2;
    mini-=(n/2)*l;
    int maxi=0;
    maxi+=((n+1)/2)*l;
    maxi-=n/2;
    if(d<mini || d>maxi)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int akt;
    int dodaj=d-mini;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            w[i]=1;
        }
        else
        {
            w[i]=l;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(dodaj>0)
        {
            akt=min(dodaj, l-1);
            if(i%2==1)
            {
                w[i]+=akt;
            }
            else
            {
                w[i]-=akt;
            }
            dodaj-=akt;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    // system("pause");
    return 0;
}