#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back 
#define fir first
#define sec second
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=300005;
int d[N],n,k,l;

int main(){
  int T=read();
  while(T--){
    n=read(),k=read(),l=read();
    vector<int>safe;
    safe.pb(0);
    int failed=0;
    for(int i=1;i<=n;i++){
      d[i]=read();
      if(d[i]>l)failed=1;
      else if(d[i]+k<=l)safe.pb(i);
    }
    safe.pb(n+1);
    if(failed){
      puts("No");continue; 
    }
    d[0]=d[n+1]=0;
    for(int i=0;i<safe.size()-1;i++){
      int now=k,down=1;
      for(int j=safe[i];j<safe[i+1];j++){
        if(j+1==n+1){
          puts("Yes");
          goto end;
        }else if(j+1==safe[i+1])break;
        else if(!down){
          if(now+1+d[j+1]>l){
            puts("No");
            goto end;
          }else now++;
        }else{
          now=min(now-1,l-d[j+1]);
          if(!now)down=0;
        }
      }
    }
    end:;
  }
  return 0;
}