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

char s0[maxn+5],t[maxn+5],w[1000000+5];
ll cnt[maxn+5][26];

ll pw[maxn+5];

vector<char> con(int now)
{
    if(now==0) return vector<char>(1,t[0]);
    auto y=con(now-1);
    auto res=y;
    res.pb(t[now]);
    for(auto c: y) res.pb(c);
    return res;
}

int fail[2200000+5],match[2200000+5];
void calfail(vector<char> &p)
{
    int j=0,l=p.size();
    fail[0]=0;
    for(int i=1;i<l;i++)
    {
        while(j && p[j]!=p[i]) j=fail[j-1];
        if(p[j]==p[i]) j++;
        fail[i]=j;
    }
    return;
}
void kmp(vector<char> &p,vector<char> &t)
{
    int n=t.size(),m=p.size(),j=0;
    for(int i=0;i<n;i++)
    {
        while(j && (j==m || p[j]!=t[i])) j=fail[j-1];
        if(p[j]==t[i]) j++;
        match[i]=j==m;
    }
    return;
}

int main()
{
    pw[0]=1;
    for(int i=1;i<=maxn;i++) pw[i]=pw[i-1]*2%mod;

    int n,q; scanf("%d%d",&n,&q);
    scanf("%s%s",s0,t);
    cnt[0][t[0]-'a']++;
    for(int i=1;i<n;i++) 
    {
        for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j]*2%mod;
        cnt[i][t[i]-'a']++;
    }

    int N=strlen(s0);
    while(q--)
    {
        int k; scanf("%d%s",&k,w);
        int L=strlen(w);
        ll ans=0;
        for(int st=0;st<=N;st++)
        {
            vector<char> x;
            int now=st,ok=1;
            for(int i=0;i<L;i++) 
            {
                if(now==N) x.pb(w[i]);
                else if(s0[now]!=w[i]) {ok=0; break;}
                now++; if(now>N) now=0;
            } 
            if(ok==0) continue;

            int W=0,M=x.size();
            if(M==0)
            {
                ans=(ans+pw[k])%mod;
                continue;
            }
            while((1<<W)-1<M) W++;
            W--;
            if(W>k-1) continue;
            auto y=con(W);
            calfail(x);
            kmp(x,y);
            int S=y.size(),num=0;
            for(int i=0;i<S;i++) if(match[i]) num++;
            ans=(ans+1ll*num*pw[k-1-W])%mod;
            
            vector<char> Y=y; Y.pb('a');
            for(auto xx: y) Y.pb(xx);
            
            for(int c=0;c<26;c++)
            {
                Y[S]='a'+c;
                kmp(x,Y);
                int num=0;
                for(int i=S;i<S+M;i++) if(match[i]) num++;
                ans=(ans+1ll*num*(cnt[k-1][c]-cnt[W][c]*pw[k-1-W]%mod+mod))%mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}