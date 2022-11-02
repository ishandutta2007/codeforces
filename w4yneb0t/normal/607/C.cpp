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
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
string s;
int n,gap;
vector<int> sa,pos,satmp,lcp;
bool cmp(int i, int j){
  if(pos[i]!=pos[j])
    return pos[i]<pos[j];
  i+=gap;
  j+=gap;
  if(i<n && j<n)
    return pos[i]<pos[j];
  return i>j;
}
void buildsa(){
  n=sz(s);
  sa=pos=satmp=lcp=vector<int>(n,0);
  forn(i,n){
    sa[i]=i;
    pos[i]=s[i];
  }
  for(gap=1;;gap*=2){
    sort(all(sa),cmp);
    satmp[0]=0;
    forn(i,n-1)
      satmp[i+1]=satmp[i]+cmp(sa[i],sa[i+1]);
    forn(i,n)
      pos[sa[i]]=satmp[i];
    if(satmp[n-1]==n-1)break;
  }
}
void buildlcp(){
  int k=0;
  forn(i,n){
    if(pos[i]==n-1)continue;
    for(int j=sa[pos[i]+1];i+k<n && j+k<n && s[i+k]==s[j+k];++k);
    lcp[pos[i]]=k;
    if(k)
      --k;
  }
}
string tp;
void fnd(){
  in cind=0;
  in ccp=0;
  while(1){
    if((n-sa[cind])==ccp){
      cout<<"NO"<<endl;
      return;
    }
    assert(n-sa[cind]>ccp);
    if(s[sa[cind]+ccp]==tp[ccp]){
      ++ccp;
      continue;
    }
    if(cind==n-1 || lcp[cind]<ccp){
      cout<<"YES"<<endl;
      return;
    }
    ++cind;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cin>>tp>>s;
  reverse(all(tp));
  forv(i,tp){
    if(tp[i]=='N'){
      tp[i]='S';
      continue;
    }
    if(tp[i]=='S'){
      tp[i]='N';
      continue;
    }
    if(tp[i]=='W'){
      tp[i]='E';
      continue;
    }
    if(tp[i]=='E'){
      tp[i]='W';
      continue;
    }
  }
  buildsa();
  buildlcp();
  fnd();
  return 0;
}