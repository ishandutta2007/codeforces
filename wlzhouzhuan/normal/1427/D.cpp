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
#define mset(s,t) memset(s,t,sizeof(s))
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
const int N=55; 
int a[N],b[N],n;
vector<vector<int>>ans;
void solve(vector<int>opt){
  int qwq=n,qaq=0;
  for(auto v:opt){
    for(int i=qwq-v+1,j=qaq+1;i<=qwq;i++,j++){
      b[i]=a[j];
    }
    qwq-=v,qaq+=v;
  }
  for(int i=1;i<=n;i++)a[i]=b[i];
}
int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  while(true){
    vector<int>opt;
    for(int i=1;i<=n;i++){
      if(a[i]==i)continue;
      if(i>1)opt.pb(i-1);
      for(int k=i;k<n;k++){
        if(a[k+1]==a[k]+1)continue;
        opt.pb(k-i+1);
        for(int j=k+1;j<=n;j++){
          if(a[j]==a[i]-1){
            if(j-k)opt.pb(j-k);
            if(n-j)opt.pb(n-j);
            //printf("find ! %d %d %d\n",i,j,k);
            break;
          }
        }
        break;
      }
      break;
    }
    if(!opt.size())break;
    //for(auto v:opt)printf("%d ",v);
    //puts(""); 
    //system("pause");
    ans.pb(opt);
    solve(opt);
  }
  printf("%d\n",ans.size());
  for(auto it:ans){
    printf("%d ",it.size());
    for(auto v:it)printf("%d ",v); 
    puts(""); 
  } 
  return 0;
}