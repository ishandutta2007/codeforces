#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define uint long long int
#define N 100005
using namespace std;
uint tab[N];
uint sumpref[N];
uint stosy[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>stosy[i];
        stosy[i]*=-1;
    }
    sort(stosy+1, stosy+1+n);
    uint odp1=0;
    for(int i=2; i<=n; i++)
    {
        odp1+=(i-1)*stosy[i];
    }
    for(int i=1; i<=n; i++)
    {
        sumpref[i]=sumpref[i-1]+stosy[i];
    }
    int q;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int zap;
        cin>>zap;
        if(zap==1)
        {
            cout<<-odp1<<" ";
        }
        else
        {
            uint pot=zap;
            uint akt=1;
            uint odp=0;
            int licz=1;
            while(akt<=n)
            {
                odp+=licz*(sumpref[min(akt+pot, (uint)n)]-sumpref[akt]);
                licz++;
                akt+=pot;
                pot*=zap;
            }
            cout<<-odp<<" ";
        }
    }
    cout<<endl;
    return 0;
}