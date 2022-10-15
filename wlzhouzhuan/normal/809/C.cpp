#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>void gcd(T &a,T &b){return b?gcd(b,a%b):a;}
template<typename T>void ckmax(T &a,T b){if(a<b)a=b;}
template<typename T>void ckmin(T &a,T b){if(a>b)a=b;}
inline int read(){
  char ch=getchar();
  int x=0,neg=0;
  while(!isdigit(ch)){neg|=ch=='-';ch=getchar();}
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return neg?-x:x;
}
template<typename T>void print(T x){
  if(x<0)putchar('-'),x=-x;
  if(x>=10)print(x/10);
  putchar(x%10+'0');
}

const ll mod=1e9+7; 
template<typename T>void add(T &a,T b){a+=b;if(a>=mod)a-=mod;}
template<typename T>void sub(T &a,T b){a-=b;if(a<0)a+=mod;}
ll cnt[32][2][2][2],sum[32][2][2][2];
ll solve(ll x,ll y,ll k){
  if(x<0||y<0||k<0)return 0ll;
  vector<int>a(31),b(31),c(31);
  for(int i=0;i<=30;i++){
    a[i]=x%2,x/=2;
    b[i]=y%2,y/=2;
    c[i]=k%2,k/=2;
  }
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  reverse(c.begin(),c.end());
  memset(cnt,0,sizeof(cnt));
  memset(sum,0,sizeof(sum));
  cnt[0][1][1][1]=1;
  sum[0][1][1][1]=0;
  for(register int i=0;i<=30;i++){
    for(register int upx=0;upx<2;upx++){
      for(register int upy=0;upy<2;upy++){
        for(register int upk=0;upk<2;upk++){
          for(register int x=0;x<2;x++){
            for(register int y=0;y<2;y++){
              int z=x^y;
              if(upx&&x&&!a[i])continue;
              if(upy&&y&&!b[i])continue;
              if(upk&&z&&!c[i])continue;
              add(cnt[i+1][upx&&(x==a[i])][upy&&(y==b[i])][upk&&(z==c[i])],cnt[i][upx][upy][upk]);
              add(sum[i+1][upx&&(x==a[i])][upy&&(y==b[i])][upk&&(z==c[i])],sum[i][upx][upy][upk]);
              add(sum[i+1][upx&&(x==a[i])][upy&&(y==b[i])][upk&&(z==c[i])],cnt[i][upx][upy][upk]*z*(1ll<<30-i)%mod);
            }
          }
        }
      }
    }
  }
  ll ans=0;
  for(register int upx=0;upx<2;upx++){
    for(register int upy=0;upy<2;upy++){
      for(register int upk=0;upk<2;upk++){
        add(ans,sum[31][upx][upy][upk]);
        add(ans,cnt[31][upx][upy][upk]);
      }
    }
  }
  return ans;
}
int main(){
  int T=read();
  while(T--){
    int x1=read(),y1=read(),x2=read(),y2=read(),k=read();
    x1--,y1--,x2--,y2--,k--;
    printf("%lld\n",(solve(x2,y2,k)-solve(x1-1,y2,k)-solve(x2,y1-1,k)+solve(x1-1,y1-1,k)+2ll*mod)%mod);
  }
  return 0;
}