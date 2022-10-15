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
const int N=200005;
char s[N];
int n,m;
void work(){
  scanf("%d%d%s",&n,&m,s+1);
  int num=0;
  for(int i=1;i<=n;i++)if(s[i]=='W')num++;
  if(num+m>=n){
    printf("%d\n",2*n-1);
    return;
  }
  int St=0,Ed=0;
  for(int i=1;i<=n;i++)if(s[i]=='W'){
    St=i;break;
  }
  for(int i=n;i>=1;i--)if(s[i]=='W'){
    Ed=i;break;
  }
  if(!St){
    printf("%d\n",max(0,2*(num+m)-1));
    return;
  }
  vector<int> gap;
  for(int i=St;i<=Ed;i++){
    int j=i;
    if(s[i]=='W')continue;
    while(j<Ed&&s[j+1]==s[i])j++;
    gap.pb(j-i+1);
    i=j;
  }
  sort(gap.begin(),gap.end());
  int len=gap.size(),M=m; 
  //printf("len=%d\n",len);
  for(auto v:gap){
    if(m>=v){
      m-=v;
      len--;
    }
  }
  //printf("len=%d\n",len);
  printf("%d\n",2*(num+M)-1-len);
}
int main(){
  int T=read();
  while(T--)work();
  return 0;
}