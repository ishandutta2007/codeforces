#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5],t[maxn+5];
int dif[maxn+5];

bool check(int n,char *s,char *t)
{
    rep(i,1,n) dif[i]=t[i]-s[i];
    per(i,1,n) if(dif[i]<0) dif[i]+=2, dif[i-1]--;
    rep(i,1,n-1) if(dif[i]>0) return 1;
    return 0;
}

int main()
{
    int n; scanf("%d%s%s",&n,s+1,t+1);
    if(s[1]!=t[1])
    {
        rep(i,1,n) putchar('1');
        puts("");
    }
    else if(t[n]=='1') puts(t+1);
    else
    {
        if(check(n,s,t)==0) puts(t+1);
        else
        {
            t[n]='1';
            puts(t+1);
        }
    }
    return 0;
}