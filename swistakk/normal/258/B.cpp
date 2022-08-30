#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define uint long long int
#define M 1000000007
#define N 20
using namespace std;
uint dp[N];
uint pre[N][N];
uint pot(uint m)
{
    uint pot=1;
    while(10*pot<=m)
    {
        pot*=10;
    }
    return pot;
}
uint f(uint m)
{
    if(m==0)
    {
        return 0;
    }
    uint aku=1;
    uint k=1;
    while(10*aku<=m)
    {
        aku*=10;
        k++;
    }
    return k;
}
uint prep(uint dlug)
{
    pre[0][0]=1;
    /* pre[1][1]=2;
    pre[0][1]=8; */
    int poz=1;
    while(poz<=dlug)
    {
        for(int i=0; i<=poz-1; i++)
        {
            pre[poz][i+1]+=2*pre[poz-1][i];
            pre[poz][i]+=8*pre[poz-1][i];
        }
        poz++;
    }
}
void licz(uint m, int p)
{
    int znacz=m/pot(m);
    
    int z=f(m);
    int szcz=0;
    if(znacz>=5)
    {
        szcz++;
        for(int i=1; i<=10; i++)
        {
            dp[i+p]+=pre[z-1][i-1];
        }
    }
    if(znacz>=8)
    {
        szcz++;
        for(int i=1; i<=10; i++)
        {
            dp[i+p]+=pre[z-1][i-1];
        }
    }
    for(int i=0; i<=10; i++)
    {
        dp[i+p]+=(znacz-szcz)*pre[z-1][i];
    }
    if(znacz==4 || znacz==7)
    {
        p++;
    }
    if(m>=10)
    {
        licz(m-znacz*pot(m), p);
    }
}
uint wynik=0;
void rek(uint gor, uint sum, int poz, uint aku)
{
    if(poz==7)
    {
        wynik+=dp[gor]*aku;
        wynik%=M;
        return;
    }
    for(int i=0; i<=10; i++)
    {
        if(sum+i<gor)
        {
            dp[i]--;
            rek(gor, sum+i, poz+1, (aku*(dp[i]+1))%M);
            dp[i]++;
        }
    }
}
        
    
    
    
    
    
int main()
{
    ios_base::sync_with_stdio(0);
    uint m;
    cin>>m;
    if(m<=7)
    {
        cout<<"0"<<endl;
        return 0;
    }
    /* if(m==8)
    {
        cout<<"1440"<<endl;
        return 0;
    } */
    /* if(m==9)
    {
        cout<<"10080"<<endl;
        return 0;
    } */
    prep(f(m)+1);
    licz(m+1, 0);
    dp[0]--;
    /* for(int i=0; i<=2; i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<pre[1][0]<<" "<<pre[1][1]<<endl; */
    for(int i=1; i<=10; i++)
    {
        rek(i, 0, 1, 1);
        wynik%=M;
    }
    cout<<wynik<<endl;
    return 0;
}