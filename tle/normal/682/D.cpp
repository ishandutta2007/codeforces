#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define SZ 2333333
typedef long long ll;
ll MOD=1000000007,cm[SZ],cmn[SZ];
ll qp(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
struct HashKMP
{
char s[SZ+1]; int n;
ll hash[SZ+1];
void pre()
{
    n=strlen(s);
    for(int i=n-1;i>=0;i--) hash[i]=(hash[i+1]+cm[n-1-i]*(s[i]-'a'+1)%MOD)%MOD;
}
ll ghash(int l,int r)
{
    return ((hash[l]-hash[r+1])*cmn[n-1-r]%MOD+MOD)%MOD;
}
int next[SZ+3];
void gnext()
{
    next[0]=-1;
    int j=-1;
    for(int i=1;s[i];i++)
    {
        while(j!=-1&&s[i]!=s[j+1]) j=next[j];
        if(s[i]==s[j+1]) ++j;
        next[i]=j;
    }
}
void kmp(char* a)
{
    int j=-1;
    for(int i=0;a[i];i++)
    {
        while(j!=-1&&s[j+1]!=a[i]) j=next[j];
        if(s[j+1]==a[i]) ++j;
        //do sth
        printf("%d w %d\n",i,j);
    }
}
}ha,hb;
void getcm()
{
    cm[0]=cmn[0]=1; ll gg=qp(31,MOD-2);
    for(int i=1;i<=1234567;i++) cm[i]=cm[i-1]*31%MOD;
    for(int i=1;i<=1234567;i++) cmn[i]=cmn[i-1]*gg%MOD;
}

int n,m,K;
int ml[1003][1003][12][2];
int main()
{
    getcm();
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s",ha.s);
    scanf("%s",hb.s);
    ha.pre(); hb.pre();
    memset(ml,-127/3,sizeof(ml));
    ml[0][0][0][0]=0;
    for(int p=0;p<=n;p++)
    for(int q=0;q<=m;q++)
    for(int i=0;i<=10;i++) ml[p][q][i][1]=0;
    for(int k=1;k<=10;k++)
    {
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(ha.s[i-1]==hb.s[j-1]) ml[i][j][k][0]=max(ml[i-1][j-1][k-1][1]+1,ml[i-1][j-1][k][0]+1);
		}
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++) ml[i][j][k][1]=max(ml[i][j][k][0],max(ml[i-1][j][k][1],ml[i][j-1][k][1]));
	}
	}
	printf("%d\n",ml[n][m][K][1]);
}