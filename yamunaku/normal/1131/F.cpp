#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;


class uf{
  public:
  vector<vector<int>> q;
  vector<int> par;
  int n;

  uf(int n1){
    n=n1;
    par=vector<int>(n);
    q=vector<vector<int>>(n);
    for(int i=0;i<n;i++){
      par[i]=i;
      q[i]=vector<int>(1,i);
    }
  }

  int root(int x){
    if(x==par[x]) return x;
    return par[x]=root(par[x]);
  }

  void uni(int x, int y){
    x=root(x),y=root(y);
    if(x==y) return;
    if(q[x].size()<q[y].size()) swap(x,y);
    par[y]=x;
    int nn=q[x].size(),mm=q[y].size();
    q[x].resize(nn+mm);
    for(int i=0;i<mm;i++){
      q[x][nn+i]=q[y][i];
    }
    q[y].clear();
  } 
  
  void ans(){
    int r=root(0);
    for(int i=0;i<n;i++){
      printf("%d ",q[r][i]+1);
    }
    printf("\n");
  }
};

int main(){
  int n;
  cin >> n;
  uf aaa(n);
  int x,y;
  for(int i=0;i<n-1;i++){
    scanf("%d %d",&x,&y);
    aaa.uni(x-1,y-1);
  }
  aaa.ans();
  return 0;
}