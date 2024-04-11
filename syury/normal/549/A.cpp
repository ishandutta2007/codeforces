#include<stdio.h>
#include<vector>
#include<map>
#include<utility>

using namespace std;

int n,m;
vector<vector<int> >a;
int ans=0;

int main(){
  scanf("%d%d",&n,&m);getc(stdin);a.resize(n);
  for(int i=0;i<n;i++){
    a[i].resize(m);
    for(int j=0;j<m;j++){
      a[i][j]=getc(stdin);
    }
    getc(stdin);
  }
  if(n==1 || m==1){printf("0");return 0;}
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m-1;j++){
      map<char,int>mp;
      mp.insert(make_pair(a[i][j],1));
      mp.insert(make_pair(a[i+1][j],1));
      mp.insert(make_pair(a[i][j+1],1));
      mp.insert(make_pair(a[i+1][j+1],1));
      if(mp.count('f')&&mp.count('a')&&mp.count('c')&&mp.count('e')){ans++;}
    }
  }
  printf("%d",ans);
  return 0;
}