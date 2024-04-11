#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
string a,s[N*N];
int n,m,tot;
ll k;

ll f[N][N],g[N][N];
ll Rank(string ss){
  int len=ss.size();
  memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
  f[n][0]=1,g[n][0]=1;
  for(register int i=n-1;i>=0;i--){
    int tail=0;
    while(i+tail<n&&tail<len&&a[i+tail]==ss[tail])tail++;
    int tag=0;
    if(i+tail>=n)tag=1;
    else if(i+tail<n&&tail>=len)tail++;
    else if(i+tail<n&&tail<len){
      if(a[i+tail]<ss[tail])tag=1;
      else tail++;
    }
    //printf("i=%d,tail=%d,tag=%d\n",i,tail,tag);
    for(register int j=0;j<=m;j++){
      if(j)f[i][j]=tag?0:g[i+tail][j-1];
      g[i][j]=g[i+1][j]+f[i][j];
      if(g[i][j]>k)g[i][j]=k+1;
      //printf("f[%d][%d]=%2d  ",i,j,f[i][j]);
    }
    //puts("");
  }
  return f[0][m];
}

int main(){
  ios::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m>>k;
  cin>>a;
  for(register int i=0;i<n;i++){
    for(register int j=i;j<n;j++){
      s[tot++]=a.substr(i,j-i+1);
    }
  }
  sort(s,s+tot,greater<string>());
  //printf("tot=%d\n",tot);
  //for(int i=0;i<tot;i++){
  //  cout<<"i="<<i<<' '<<s[i]<<" rank="<<Rank(s[i])<<'\n';
  //}
  //exit(0);
  
  int l=0,r=tot,ans=0;
  while(l<r){
    int mid=l+r>>1;
    if(Rank(s[mid])<k)l=mid+1,ans=mid;
    else r=mid;
  } 
  cout<<s[ans]<<'\n';
  return 0;
}