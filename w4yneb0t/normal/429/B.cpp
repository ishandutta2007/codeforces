#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
int a[1009][1009];
int bf11[1009][1009];
int bf12[1009][1009];
int bf21[1009][1009];
int bf22[1009][1009];
in n,m;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  forn(i,n)
    forn(j,m)
    cin>>a[i][j];
  bf11[0][0]=a[0][0];
  bf12[0][m-1]=a[0][m-1];
  bf21[n-1][0]=a[n-1][0];
  bf22[n-1][m-1]=a[n-1][m-1];
  for(int i=0;i<n;i++){
    for(in j=0;j<m;j++){
      if(i==0 && j==0)
	continue;
      bf11[i][j]=0;
      if(i>0)
	bf11[i][j]=bf11[i-1][j];
      if(j>0 && bf11[i][j-1]>bf11[i][j])
	bf11[i][j]=bf11[i][j-1];
      bf11[i][j]+=a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(in j=m-1;j>=0;j--){
      if(i==0 && j==m-1)
	continue;
      bf12[i][j]=0;
      if(i>0)
	bf12[i][j]=bf12[i-1][j];
      if(j<m-1 && bf12[i][j+1]>bf12[i][j])
	bf12[i][j]=bf12[i][j+1];
      bf12[i][j]+=a[i][j];
    }
  }
  for(int i=n-1;i>=0;i--){
    for(in j=0;j<m;j++){
      if(i==n-1 && j==0)
	continue;
      bf21[i][j]=0;
      if(i<n-1)
	bf21[i][j]=bf21[i+1][j];
      if(j>0 && bf21[i][j-1]>bf21[i][j])
	bf21[i][j]=bf21[i][j-1];
      bf21[i][j]+=a[i][j];
    }
  }
  for(int i=n-1;i>=0;i--){
    for(in j=m-1;j>=0;j--){
      if(i==n-1 && j==m-1)
	continue;
      bf22[i][j]=0;
      if(i<n-1)
	bf22[i][j]=bf22[i+1][j];
      if(j<m-1 && bf22[i][j+1]>bf22[i][j])
	bf22[i][j]=bf22[i][j+1];
      bf22[i][j]+=a[i][j];
    }
  }
  in best=-1;
  in scc;
  for(in i=1;i<n-1;i++){
    for(in j=1;j<m-1;j++){
      scc=bf11[i-1][j]+bf22[i+1][j]+bf21[i][j-1]+bf12[i][j+1];
      if(scc>best)
	best=scc;
      scc=bf11[i][j-1]+bf22[i][j+1]+bf21[i+1][j]+bf12[i-1][j];
      if(scc>best)
	best=scc;
    }
  }
  cout<<best<<endl;
  return 0;
}