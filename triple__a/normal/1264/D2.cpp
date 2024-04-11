#include<bits/stdc++.h>
using namespace std;

const int maxn=2000007;
const int mod=998244353;
string s;
int l[maxn],r[maxn],n;
int f[maxn],g[maxn],v[maxn];

int qp(int u,int v){
    int ans=1,t=u;
    while (v){
        if (v&1) ans=1ll*ans*t%mod;
        t=1ll*t*t%mod, v>>=1;
    }
    return ans;
}

void inv(){
    v[0]=1;
    for (int i=1;i<maxn;++i){
        v[i]=1ll*v[i-1]*i%mod;
    }
}

int mult(int u,int v){
    return 1ll*u*v%mod;
}

int C(int a,int b){
    if (b>a) return 0;
    return mult(v[a],qp(mult(v[b],v[a-b]),mod-2));
}

int f0(int u){
    return u<0?0:f[u];
}

int g0(int u){
    return u<0?0:g[u];
}
int main(){
    inv();
    cin>>s;
    n=s.size();
    for (int i=0;i<n;++i){
        if (s[i]=='(') l[i+1]=1;
        if (s[i]==')') r[i+1]=1;
    }
    for (int i=1;i<=n;++i) l[i]+=l[i-1],r[i]+=r[i-1];
    for (int i=0;i<=n;++i) f[i]=C(n-r[n]-l[n],i),g[i]=C(n-r[n]-l[n]-1,i);
    for (int i=1;i<=n;++i) f[i]=(f[i]+f[i-1])%mod,g[i]=(g[i]+g[i-1])%mod;
    int ans=0;
    for (int i=1;i<=n;++i){
        if (s[i-1]=='('){
            ans=(ans+f0(n-i-l[n]+l[i]-l[i-1]-1))%mod;
        }
        if (s[i-1]=='?') ans=(ans+g0(n-i-l[n]+l[i]-l[i-1]-1))%mod;
    } 
    cout<<ans<<endl;
    return 0;
}