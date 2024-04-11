#include <iostream>
#include <algorithm>
#define M 8192
using namespace std;
int drz[2*M+5];
int czyt(int a, int b)
{
    a+=M-1;
    b+=M-1;
    int maxi=drz[a];
    maxi=max(maxi, drz[b]);
    while(a/2!=b/2)
    {
        if(a%2==0)
        {
            maxi=max(maxi, drz[a+1]);
        }
        if(b%2==1)
        {
            maxi=max(maxi, drz[b-1]);
        }
        a/=2;
        b/=2;
    }
    return maxi;
}
void akt(int a, int w)
{
    a+=M-1;
    while(a)
    {
        drz[a]=max(drz[a], w);
        a/=2;
    }
    /* a+=M-1;
    b+=M-1;
    drz[a]=max(drz[a], w);
    drz[b]=max(drz[b], w);
    while(a/2!=b/2)
    {
        if(a%2==0)
        {
            drz[a+1]=max(drz[a+1], w);
        }
        if(b%2==1)
        {
            drz[b-1]=max(drz[b-1], w);
        }
        a/=2;
        b/=2;
    } */
}
int main()
{
    int n, m;
    cin>>n>>m;
    double wtf;
    int gat;
    for(int i=1; i<=n; i++)
    {
        cin>>gat>>wtf;
        int war=czyt(1, gat);
        akt(gat, war+1);
    }
    cout<<n-czyt(1, n)<<endl;
    return 0;
}