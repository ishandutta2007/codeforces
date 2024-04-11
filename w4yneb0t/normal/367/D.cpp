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
vector<bool> ok;
in n,m,d;
//vector<in> st[29];
in cnb[29];
in a[100009];
vector<in> bms[29];
queue<in> q[2];
in chs[23][23];
in si(in msk){
  in r=0;
  for(in j=0;j<m;j++)
    if(msk&(1LL<<j))
      r++;
  return r;
}
int main(){
  cin>>n>>m>>d;
  for(in i=0;i<23;i++){
    chs[i][0]=chs[i][i]=1;
    for(in j=1;j<i;j++)
      chs[i][j]=chs[i-1][j]+chs[i-1][j-1];
  }
  ok.resize(1LL<<m,1);
  for(in i=0;i<m;i++){
    in tsz,tin;
    cin>>tsz;
    for(in j=0;j<tsz;j++){
      cin>>tin;
      tin--;
      //st[i].push_back(tin);
      a[tin]=i;
    }
  }
  for(in i=0;i<d;i++)
    cnb[a[i]]++;
  in bmsk;
  for(in i=d-1;i<n;i++){
    bmsk=0;
    for(in j=0;j<m;j++)
      if(cnb[j])
	bmsk+=(1LL<<j);
    bms[si(bmsk)].push_back(bmsk);
    if(i!=n-1){
      cnb[a[i-d+1]]--;
      cnb[a[i+1]]++;
    }
  }
  in bok=0;
  in sw=0;
  in nw=0;
  in bad;
  for(in s=0;s<=m;s++){
    bad=0;
    sw=s%2;
    nw=!sw;
    for(in j=0;j<bms[s].size();j++){
      if(!ok[bms[s][j]])
	continue;
      ok[bms[s][j]]=0;
      q[sw].push(bms[s][j]);
    }
    bad=q[sw].size();
    if(bad<chs[m][s])
      bok=s;
    else
      break;
    in u,v;
    while(!q[sw].empty()){
      u=q[sw].front();
      q[sw].pop();
      for(in j=0;j<m;j++){
	if((1LL<<j)&u)
	  continue;
	v=u|(1LL<<j);
	if(!ok[v])
	  continue;
	ok[v]=0;
	q[nw].push(v);
      }
    }
  }
  cout<<m-bok<<endl;
  return 0;
}