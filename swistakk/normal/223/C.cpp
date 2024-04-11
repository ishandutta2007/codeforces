#include <iostream>
#define P 1000000007
#define N 2005
#define uint long long int
using namespace std;
uint tab[N];
uint newt[N];
uint sil[N];
uint il[N];
uint spot(uint a, uint pot)
{
    uint tmp=a;
    uint akt=1;
    while(pot)
    {
        if(pot%2==1)
        {
            akt*=tmp;
            akt%=P;
        }
        tmp*=tmp;
        tmp%=P;
        pot/=2;
    }
    return akt;
}
uint odw(int c)
{
    return spot(c, P-2);
}
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>tab[i];
    }
    if(k==0)
    {
        for(int i=1; i<=n; i++)
        {
            cout<<tab[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    sil[0]=1;
    for(int i=1; i<=n; i++)
    {
        sil[i]=i*sil[i-1]%P;
    }
    il[0]=k;
    for(int i=1; i<=n; i++)
    {
        il[i]=(k+i)*il[i-1]%P;
    }
    
    newt[0]=1;
    for(int i=1; i<=n; i++)
    {
        newt[i]=newt[i-1]*(k+i-1)%P*odw(i)%P;
        // cout<<i<<" "<<newt[i]<<endl;
    }
    
    cout<<tab[1]<<" ";
    for(int i=2; i<=n; i++)
    {
        uint sum=0;
        for(int j=1; j<=i; j++)
        {
            sum+=newt[i-j]*tab[j]%P;
            sum%=P;
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}