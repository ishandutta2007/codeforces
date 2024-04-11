#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5],t[maxn+5];
int zL,oL,zR,oR;

int fail[maxn+5];
void calfail(char *p)
{
    int j=0,l=strlen(p);
    fail[0]=0;
    rep(i,1,l-1)
    {
        while(j && p[j]!=p[i]) j=fail[j-1];
        if(p[j]==p[i]) j++;
        fail[i]=j;
    }
    return;
}
int main()
{
    scanf("%s",s);
    scanf("%s",t);
    int n=strlen(s);
    int m=strlen(t);

    calfail(t);
    int L=fail[m-1],R=m-L;
    int zero=0,one=0;
    rep(i,0,n-1) if(s[i]=='0') zero++; else one++;
    rep(i,0,L-1) if(t[i]=='0') zL++; else oL++;
    rep(i,L,m-1) if(t[i]=='0') zR++; else oR++;
    int ptr=0;
    if(zero>=zL && one>=oL)
    {
        memcpy(s,t,L);
        zero-=zL;
        one-=oL;
        ptr+=L;
        while(zero>=zR && one>=oR)
        {
            memcpy(s+ptr,t+L,R);
            zero-=zR;
            one-=oR;
            ptr+=R;
        }
        while(zero--) s[ptr++]='0';
        while(one--) s[ptr++]='1';
    }
    puts(s);
    return 0;
}