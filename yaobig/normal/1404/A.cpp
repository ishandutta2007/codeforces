#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];

int main()
{
    int cas; scanf("%d",&cas);
    while(cas--)
    {
        int n,k; scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        bool ok=1;
        int cnt0=0,cnt1=0;
        rep(st,1,k)
        {
            bool is0=0,is1=0;
            for(int i=st;i<=n;i+=k) 
            {
                if(s[i]=='0') is0=1;
                if(s[i]=='1') is1=1;
            }
            if(is0 && is1) ok=0;
            if(is0) cnt0++;
            if(is1) cnt1++;
        }
        if(cnt0>k/2 || cnt1>k/2) ok=0;
        puts(ok?"YES":"NO");
    }
    return 0;
}