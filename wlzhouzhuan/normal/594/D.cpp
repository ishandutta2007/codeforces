#pragma GCC optimize(2)
#pragma GCC optimize(3) 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e6+5;
const int NUM=1e6+5;
const ll mod=1e9+7;

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=buf;
int getc(){
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
int read(){
  int x=0;
  char ch=getc();
  while(!isdigit(ch))ch=getc();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getc();
  return x;
}
void print(int x){
  if(x>9)print(x/10);
  *O++=x%10+'0';
}

ll qpow(ll a,ll b=mod-2){
  ll res=1;
  while(b>0){
    if(b&1)res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return res;
}
ll mul[N],imul[N],a[N];
int n,q;

bool vis[NUM];
int pr[NUM],len,minp[NUM],mulp[NUM],inv[NUM];
ll val[NUM],ival[NUM];
void init(int n){
  minp[1]=mulp[1]=inv[1]=1;
  for(register int i=2;i<=n;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
  for(register int i=2;i<=n;i++){
    if(!vis[i]){
      pr[len++]=i,minp[i]=mulp[i]=i;
      val[i]=1ll*(i-1)*inv[i]%mod;
      ival[i]=1ll*i*inv[i-1]%mod;
    }
    for(register int j=0,v;j<len&&pr[j]*i<=n;j++){
      v=pr[j]*i,vis[v]=1;
      if(i%pr[j]==0){
        minp[v]=pr[j];
        mulp[v]=mulp[i]*pr[j];
        break;
      }
      minp[v]=mulp[v]=pr[j];
    }
  }
}

ll c[N],ans[N];
void upd(int x,ll dlt){
  while(x<=n){
    c[x]=c[x]*dlt%mod;
    x+=x&-x;
  }
}
ll qry(int x){
  ll res=1;
  while(x){
    res=res*c[x]%mod;
    x^=x&-x;
  }
  return res;
}

int lst[NUM],fir[N],nxt[N],L[N];
void update(int i,int p){
  if(p<=100){lst[p]=i;return;}
  if(lst[p])upd(lst[p],ival[p]);
  lst[p]=i,upd(i,val[p]);
}

int main(){
  O=obuf;
  init(1e6);
  n=read();
  mul[0]=imul[0]=1ll;
  for(register int i=1;i<=n;++i){
    a[i]=read(),c[i]=1;
    mul[i]=mul[i-1]*a[i]%mod;
  }
  imul[n]=qpow(mul[n],mod-2);
  for(register int i=n-1;i>=1;--i)imul[i]=imul[i+1]*a[i+1]%mod;
  q=read();
  int l,r;
  for(register int i=1;i<=q;++i){
    l=read(),r=read();
    if(l>r)swap(l,r);
    L[i]=l,nxt[i]=fir[r],fir[r]=i;
  }
  for(register int r=1;r<=n;++r){
    int i=r;
    while(a[i]>1){
      update(i,minp[a[i]]);
      a[i]/=mulp[a[i]];
    }
    int l,id;
    for(register int _=fir[r];_;_=nxt[_]){
      l=L[_],id=_;
      ans[id]=qry(r)*qpow(qry(l-1))%mod*mul[r]%mod*imul[l-1]%mod;
      for(register int k=0;k<25;++k){
        if(lst[pr[k]]>=l)ans[id]=ans[id]*val[pr[k]]%mod;
      }
    }
  }
  for(register int i=1;i<=q;i++)print(ans[i]),*O++='\n';
  fwrite(obuf,O-obuf,1,stdout);
  return 0;
}