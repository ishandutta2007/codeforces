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
in x[100009];
in y[100009];
in n;
int prt[100009][18];
int ht[100009];
int ssz=0;
int slc[100009];
bool bentup(int a, int b, int c){
  in x1=x[b]-x[a];
  in y1=y[b]-y[a];
  in x2=x[c]-x[b];
  in y2=y[c]-y[b];
  return (y1*x2)<(y2*x1);
}
bool bentdown(int a, int b, int c){
  in x1=x[b]-x[a];
  in y1=y[b]-y[a];
  in x2=x[c]-x[b];
  in y2=y[c]-y[b];
  return (y1*x2)>(y2*x1);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  forn(i,n)
    cin>>x[i]>>y[i];
  ssz=1;
  slc[0]=n-1;
  prt[n-1][0]=n-1;
  /*  cout<<bentup(0,1,2)<<endl;
  cout<<bentup(0,2,3)<<endl;
  cout<<bentup(0,3,4)<<endl;
  cout<<endl<<endl;*/
  for(in i=n-2;i>=0;i--){
    //cout<<ssz<<endl;
    int mn,mx,md;
    mn=0;
    mx=ssz;
    while(mx-mn>1){
      md=(mn+mx)/2-1;
      if(bentup(i,slc[md+1],slc[md]))
	mx=md+1;
      else
	mn=md+1;
    }
    prt[i][0]=slc[mn];
    while(ssz>1 && !bentdown(i,slc[ssz-1],slc[ssz-2]))
      ssz--;
    slc[ssz++]=i;
  }
  ht[n-1]=0;
  for(int i=n-2;i>=0;i--){
    ht[i]=ht[prt[i][0]]+1;
  }/*
  forn(i,n)
    cout<<prt[i][0]<<" "<<ht[i]<<endl;*/
  for(int j=1;j<18;j++){
    for(int i=0;i<n;i++){
      prt[i][j]=prt[prt[i][j-1]][j-1];
    }
  }
  int m;
  cin>>m;
  int a,b,ta,tb;
  forn(zz,m){
    cin>>a>>b;
    a--;
    b--;
    if(ht[b]<ht[a]){
      a^=b;
      b^=a;
      a^=b;
    }
    //cout<<a<<" "<<b<<endl;
    for(int i=17;i>=0;i--){
      if(ht[b]-(1<<i)<ht[a])
	continue;
      b=prt[b][i];
    }
    for(int i=17;i>=0;i--){
      ta=prt[a][i];
      tb=prt[b][i];
      if(ta!=tb){
	a=ta;
	b=tb;
      }
    }
    if(a!=b){
      a=prt[a][0];
      b=prt[b][0];
    }
    cout<<a+1<<" ";
  }
  cout<<"\n";
  return 0;
}