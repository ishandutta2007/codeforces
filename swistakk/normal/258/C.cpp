#include <iostream>
#include <vector>
#define N 100005
#define uint long long int
#define M 1000000007
using namespace std;
uint spot(uint a, uint b)
{
    uint akt=1;
    uint pot=a;
    while(b)
    {
        if(b%2==1)
        {
            akt*=pot;
            akt%=M;
        }
        pot*=pot;
        pot%=M;
        b/=2;
    }
    return akt;
}
uint ile[N];
uint gora[N];
uint d[N];
vector<int> dziel[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int b;
        cin>>b;
        ile[b]++;
    }
    for(int i=N-2; i>=1; i--)
    {
        gora[i]=gora[i+1]+ile[i];
    }
    for(int i=1; i<=N-2; i++)
    {
        for(int j=1; i*j<=N-2; j++)
        {
            dziel[i*j].push_back(i);
        }
    }
    for(int i=1; i<=N-2; i++)
    {
        d[i]=dziel[i].size();
    }
    uint wynik=0;
    uint aku1=0;
    uint aku2=0;
    uint z=0;
    for(int i=1; i<=N-2; i++)
    {
        aku1=spot(d[i], gora[i]) -  spot(d[i]-1, gora[i]);
        aku1=(aku1+M)%M;
        aku2=gora[i];
        aku1%=M;
        for(int j=d[i]-2; j>=0; j--)
        {
            z=gora[dziel[i][j]]-aku2;
            aku1*=spot(j+1, z);
            aku1%=M;
            aku2=gora[dziel[i][j]];
        }
        /* if(i<=6)
        {
            cout<<i<<" "<<aku1<<" "<<gora[i]<<endl;
        } */
        wynik+=aku1;
        wynik%=M;
    }
    cout<<wynik<<endl;
    return 0;
}