#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

string s1,s2;
int re[N],f[N],g[N];
int main(){
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    re[1]=0;
    FOR(i,2,m){
        int pos=re[i-1];
        while (pos&&s2[i-1]!=s2[pos]) pos=re[pos];
        re[i]=pos+(s2[i-1]==s2[pos]);
    }
    int cur=0,L=-1;
    f[0]=g[0]=1;
    FOR(i,1,n){
        f[i]=f[i-1];
        while (cur&&s1[i-1]!=s2[cur]) cur=re[cur];
        cur+=(s1[i-1]==s2[cur]);
        if (cur==m) L=i-m,cur=re[m];
        if (L!=-1) f[i]=(f[i]+g[L])%MOD;
        g[i]=(g[i-1]+f[i])%MOD;
//        printf("%d %d %d\n",i,L,f[i]);
    }
    cout<<(f[n]+MOD-1)%MOD;
}