#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

LL dp[44][44], P[44];


int main()
{
    LL n, t, pot=-1, w=0;
   // scanf("%d%d", &n, &t);
    cin>> n >> t;
    n++;
    P[0]=1;
    for(int i=1; i<44; i++) P[i]=P[i-1]*2;
    dp[0][0]=1;
    for(int i=1; i<44; i++)
    {
        for(int j=0; j<44; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>0) dp[i][j]+=dp[i-1][j-1];
        }
    }
    for(int i=0; i<44; i++) if(P[i]==t) pot=i;
    if(pot==-1)
    {
        //printf("0\n");
        cout<< "0\n";
        return 0;
    }
    LL li=0;
    while(2*P[li]-1<=n) {w+=dp[li][pot]; li++;}
    n-=P[li]-1;
    for(int i=li-1; i>=0; i--)
    {
        if(n>=P[i])
        {
            if(pot>=0) w+=dp[i][pot];
            n-=P[i];
            pot--;
        }
    }
    if(t==1) w--;
    cout<< w << "\n";
    return 0;
}