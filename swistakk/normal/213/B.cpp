#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define M 1000000007
#define uint long long int
#define N 105
using namespace std;
uint o[N];
uint spot(uint a, uint b)
{
    uint akt=1;
    uint tmp=a;
    while(b)
    {
        if(b%2==1)
        {
            akt*=tmp;
            akt%=M;
        }
        tmp*=tmp;
        tmp%=M;
        b/=2;
    }
    return akt;
}
uint odw(int a)
{
    return spot(a, M-2);
}
uint dp[12][N];
uint a[15];
uint sil[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    o[1]=1;
    sil[1]=1;
    o[0]=1;
    for(int i=2; i<=n; i++)
    {
        o[i]=odw(i)*o[i-1];
        o[i]%=M;
        sil[i]=i*sil[i-1];
        sil[i]%=M;
    }
    dp[0][0]=1;
    int sum=0;
    for(int i=1; i<=10; i++)
    {
        
        cin>>a[i];
        sum+=a[i];
        for(int j=a[i]; j<=n; j++)
        {
            for(int k=0; k<=j-a[i]; k++)
            {
                dp[i][j]+=dp[i-1][k]*o[j-k];
                dp[i][j]%=M;
            }
        }
    }
    uint wynik=0;
    for(int i=1; i<=n; i++)
    {
        // cout<<dp[10][i]<<endl;
        // cout<<dp[10][i]*sil[i]<<endl;
        wynik+=dp[10][i]*sil[i];
        wynik%=M;
    }
    a[1]--;
    for(int i=1; i<=10; i++)
    {
        for(int j=max(0ll, a[i]); j<=n; j++)
        {
            dp[i][j]=0;
            for(int k=0; k<=j-a[i]; k++)
            {
                dp[i][j]+=dp[i-1][k]*o[j-k];
                dp[i][j]%=M;
            }
        }
    }
    for(int i=1; i<=n-1; i++)
    {
        wynik-=dp[10][i]*sil[i];
        wynik%=M;
    }
    if(sum==0)
    {
        wynik--;
    }
    cout<<(wynik+M)%M<<endl;
    
    
    
    
   //  system("pause");
    return 0;
}
/*
2
0 0 0 0 0 0 0 0 0 0
*/