#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
typedef long long ll;
const ll mod=1000000007;
int g[1000001];

int calc(int x){
  if(g[x]!=-1) return g[x];
  if(x<10)return g[x]=x;
  ll ret=1;
  int i=x;
  while(i>0){
    int j=i%10;
    if(j!=0) ret*=j;
    i/=10;
    }
  return g[x]=calc(ret);
  }

int main(){
  int num[10][1000001];
  rep(i,10)num[i][0]=0;
  rep(i,1000000)g[i+1]=-1;
  rep(i,1000000){
    rep(k,10)num[k][i+1]=num[k][i];
    int j=calc(i+1);
    num[j][i+1]++;
    }
  int n;cin>>n;
  rep(i,n){
    int l,r,k;
    cin>>l>>r>>k;
    cout<<num[k][r]-num[k][l-1]<<endl;
    }
  return 0;        
  }