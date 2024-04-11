#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in n,m,x;
vector<vector<in> > pos[2];
in mdl=1000000007LL;
in fc=1;
int main(){
  in sw=0;
  in nw=0;
  cin>>n>>m>>x;
  if(n>m){
    cout<<"0"<<endl;
    return 0;
  }
  for(in i=1;i<=n;i++){
    fc*=i;
    fc%=mdl;
  }
  x--;
  for(in i=0;i<2;i++)
    pos[i].resize(n+2,vector<in>(n+2,0));
  pos[0][0][0]=1;
  for(in i=0;i<m;i++){
    sw=i%2;
    nw=!sw;
    for(in j=0;j<=n;j++){
      for(in k=0;k<=j;k++){
	pos[nw][j][k]=0;
	pos[sw][j][k]%=mdl;
      }
    }
    for(in j=0;j<=n;j++){
      for(in k=0;k<=j;k++){
	for(in op=0;op<2;op++){
	  if(i==x && op==0)
	    continue;
	  for(in cl=0;cl<2;cl++){
	    pos[nw][j+op][k+cl]+=pos[sw][j][k];
	  }
	}
      }
    }
  }
  cout<<((pos[nw][n][n]%mdl)*fc)%mdl<<endl;
  return 0;
}