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
const int N=1000005;
const int inf=1e9;
char str[N];
int sum[N],n;
int a[N],len;
int dp[N];
int query(int l,int r){
  if(l<0)return inf;
  else if(l>r)return 0;
  else return sum[r]-sum[l-1];
}
bool check(int mid){
  //printf("mid=%d\n",mid);
  for(int i=0;i<=len;i++)dp[i]=-inf;
  dp[0]=0;
  for(int i=1;i<=len;i++){
    //
    if(query(dp[i-1]+1,a[i]-1)<=0)ckmax(dp[i],a[i]+mid);
    //
    if(query(dp[i-1]+1,a[i]-mid-1)<=0)ckmax(dp[i],a[i]);
    //i-1
    if(i>=2&&query(dp[i-2]+1,min(a[i-1]-1,a[i]-mid-1))<=0)ckmax(dp[i],a[i-1]+mid); 
    //printf("dp[%d]=%d\n",i,dp[i]);
  }
  return query(dp[len]+1,n)<=0;
}
int main(){
  scanf("%d%s",&n,str+1);
  int B=0,D=0;
  for(int i=1;i<=n;i++){
    if(str[i]=='*')B++;
    if(str[i]=='P'){
      D++;
      a[++len]=i;
    }
    sum[i]=sum[i-1]+(str[i]=='*');
  }
  if(D==1){
    int Lmost=0,L=0;
    int Rmost=0,R=0;
    int pos;
    for(int i=1;i<=n;i++)if(str[i]=='P'){
      pos=i;break;
    } 
    for(int i=pos-1;i>=1;i--)if(str[i]=='*'){
      Lmost=max(Lmost,pos-i);
      L++;
    }
    for(int i=pos+1;i<=n;i++)if(str[i]=='*'){
      Rmost=max(Rmost,i-pos);
      R++;
    }
    if(L!=R){
      if(L>R)printf("%d %d\n",L,Lmost);
      else printf("%d %d\n",R,Rmost);
    }
    else printf("%d %d\n",L,min(Lmost,Rmost));
    return 0; 
  }
  printf("%d ",B);
  int l=0,r=1e6;
  while(l<r){
    int mid=l+r>>1;
    if(check(mid))r=mid;
    else l=mid+1;
  }
  printf("%d\n",l);
  return 0;
}