#include <iostream>
#include <vector>
#include <algorithm>
#define uint long long int
#define N 100005
using namespace std;
uint tab[N];
int wz[N];
int main()
{
    ios_base::sync_with_stdio(0);
    uint n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>tab[i];
        wz[i]=1;
    }
    sort(tab+1, tab+1+n);
    int wynik=0;
    for(int i=n; i>=1; i--)
    {
        if(wz[i]==1)
        {
            wynik++;
            uint kl=1, kp=i, aktc, faj;
            while(kl<=kp)
            {
                aktc=(kl+kp)/2;
                if(k*tab[aktc]==tab[i])
                {
                    wz[aktc]=0;
                    break;
                }
                if(k*tab[aktc]>tab[i])
                {
                    kp=aktc-1;
                }
                else
                {
                    kl=aktc+1;
                }
            }
        }
    }
    cout<<wynik<<endl;
    return 0;
}