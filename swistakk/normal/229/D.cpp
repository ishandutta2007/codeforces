#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#define M 8192
#define N 5005
#define INF 1000000000
using namespace std;
// int drz[2*M];
int h[N];
int dp[N][N];
int pre[N];
int ziom[N];
int palec[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
        pre[i]=pre[i-1]+h[i];
    }
    int kl, kp, aktc, faj;
    for(int i=1; i<=n; i++)
    {
        dp[0][i]=INF;
        palec[i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            dp[i][j]=INF;
            ziom[j]=INF;
        }
        dp[i][1]=pre[i];
        for(int j=2; j<=i; j++)
        {
            kl=1;
            kp=n;
            faj=-1;
            int akth=pre[i]-pre[j-1];
            while(dp[j-1][palec[j-1]+1]<=akth)
            {
                palec[j-1]++;
                /*
                aktc=(kl+kp)/2;
                if(dp[j-1][aktc]<=akth)
                {
                    faj=aktc;
                    kl=aktc+1;
                }
                else
                {
                    kp=aktc-1;
                } */
            }
            faj=palec[j-1];
            if(dp[j-1][1]<=akth)
            {
                ziom[faj+1]=min(ziom[faj+1], akth);
            }
        }
        for(int j=n; j>=1; j--)
        {
            dp[i][j]=min(dp[i][j+1], dp[i][j]);
            dp[i][j]=min(dp[i][j], ziom[j]);
        }
    }
    int licz=1;
    while(dp[n][licz+1]<INF)
    {
        licz++;
    }               
    cout<<n-licz<<endl; 
    
    /* for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }    */       
    
    
    // system("pause");
    return 0;
}
/*
5
4 4 3 2 1
*/