#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in n,m,q;
bool vt[50][50];
vector<vector<vector<vector<bool> > > > cc,isp;
vector<vector<vector<vector<int> > > > rts;
bool is(in a, in b, in c, in d){
  if(a>c || b>d)
    return 1;
  return isp[a][b][c][d];
}
int rt(in a, in b, in c, in d){
  if(a>c || b>d)
    return 0;
  if(cc[a][b][c][d])
    return rts[a][b][c][d];
  cc[a][b][c][d]=1;
  rts[a][b][c][d]+=rt(a+1,b,c,d)+rt(a,b+1,c,d)+rt(a,b,c-1,d)+rt(a,b,c,d-1);
  rts[a][b][c][d]-=rt(a+1,b+1,c,d)+rt(a+1,b,c-1,d)+rt(a+1,b,c,d-1)+rt(a,b+1,c-1,d)+rt(a,b+1,c,d-1)+rt(a,b,c-1,d-1);
  rts[a][b][c][d]+=rt(a+1,b+1,c-1,d)+rt(a+1,b+1,c,d-1)+rt(a+1,b,c-1,d-1)+rt(a,b+1,c-1,d-1);
  rts[a][b][c][d]-=rt(a+1,b+1,c-1,d-1);
  isp[a][b][c][d]=is(a+1,b,c,d)&is(a,b+1,c,d)&vt[a][b];
  rts[a][b][c][d]+=isp[a][b][c][d];
  return rts[a][b][c][d];
}
int main(){
  cin>>n>>m>>q;
  char vcr[50][50];
  for(in i=0;i<n;i++)
    for(in j=0;j<m;j++){
      cin>>vcr[i][j];
      vt[i][j]=(vcr[i][j]=='0');
    }
  cc.resize(n,vector<vector<vector<bool> > >(m,vector<vector<bool> >(n,vector<bool>(m,0))));
  isp=cc;
  rts.resize(n,vector<vector<vector<int> > >(m,vector<vector<int> >(n,vector<int>(m,0))));
  for(in i=0;i<q;i++){
    in a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;
    b--;
    c--;
    d--;
    cout<<rt(a,b,c,d)<<endl;
  }
  return 0;
}