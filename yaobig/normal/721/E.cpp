#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int l[maxn+5],r[maxn+5];
int dp[maxn+5],pos[maxn+5];


int main()
{
    int L,n,p,t; scanf("%d%d%d%d",&L,&n,&p,&t);
    rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
    
    pos[0]=-inf;
    int ptr=0;
    rep(i,1,n)
    {
        dp[i]=dp[i-1]; pos[i]=pos[i-1];
        while(ptr<i && pos[ptr]+t<=r[i]-p) 
        {
            int c=(r[i]-max(l[i],pos[ptr]+t))/p;
            int ndp=dp[ptr]+c;
            int npos=max(l[i],pos[ptr]+t)+p*c;
            //printf("??? %d: %d %d\n",ptr,ndp,npos);
            if(ndp>dp[i] || (ndp==dp[i] && npos<=pos[i])) dp[i]=ndp,pos[i]=npos;
            ptr++;
        }
        ptr--;
        //printf("? %d: %d\n",i,dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}