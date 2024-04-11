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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mdl=1000000007LL;
string s;
int n,gap;
VI sa,pos,satmp,lcp;
bool cmp(int i, int j){
  if(pos[i]!=pos[j])
    return pos[i]<pos[j];
  i+=gap;
  j+=gap;
  if(i<n && j<n)
    return pos[i]<pos[j];
  return i>j;
}
void buildsa(){//builds SA of s (no other input): sa[i] is the starting point of the i-th smallest suffix, pos[sa[i]]==i
  n=sz(s);
  sa=pos=satmp=lcp=VI(n,0);
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
void buildlcp(){//call buildsa first. builds longest common prefixes. lcp[i] is the length of the lcp of the i-th and (i+1)th suffix. lcp[n-1] is unset, don't forget to set it manually
  int k=0;
  forn(i,n){
    if(pos[i]==n-1)continue;
    for(int j=sa[pos[i]+1];i+k<n && j+k<n && s[i+k]==s[j+k];++k);
    lcp[pos[i]]=k;
    if(k)
      --k;
  }
}
string x;
VVI wtdup,spaup,minlcp;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>x;
  s=x;
  buildsa();
  buildlcp();
  in n=sz(x);
  wtdup.resize(n+1,VI(n+1,0));
  spaup.resize(n+1,VI(n+1,-1));
  minlcp.resize(n+1,VI(n+1,1000000000));
  forn(i,n-1){
    minlcp[i][i]=lcp[i];
    for(in j=i+1;j<n-1;++j)
      minlcp[i][j]=min(lcp[j],minlcp[i][j-1]);
  }
  in critst,crited;
  VI spsol(n+1,-1);
  forn(ed,n){
    for(in st=ed;st>=0;st--){
      if(x[st]=='0'){
	wtdup[ed][st]=wtdup[ed][st+1];
	spaup[ed][st]=spaup[ed][st+1];
	continue;
      }
      crited=st-1;
      critst=crited+(st-ed);
      if(st==0){
	wtdup[ed][st]=(wtdup[ed][st+1]+1);
	if(wtdup[ed][st]==mdl)wtdup[ed][st]=0;
	spaup[ed][st]=1;
	spsol[0]=1;
	continue;
      }
      if(critst>=0){
	if(pos[st]<pos[critst] && minlcp[pos[st]][pos[critst]-1]<=ed-st)
	  ++critst;
      }
      else
	critst=0;
      wtdup[ed][st]=wtdup[ed][st+1]+wtdup[crited][critst];
      if(wtdup[ed][st]>=mdl)wtdup[ed][st]-=mdl;
      spaup[ed][st]=1+spaup[crited][critst];
      if(spaup[ed][st]==0)
	spaup[ed][st]=-1;
      spsol[st]=spaup[ed][st];
      if(spaup[ed][st]==-1)
	spaup[ed][st]=spaup[ed][st+1];
      else{
	if(spaup[ed][st+1]!=-1)
	  spaup[ed][st]=min(spaup[ed][st],spaup[ed][st+1]);
      }
    }
  }
  cout<<wtdup[n-1][0]<<endl;
  in bst=mdl+3;
  for(in i=n-1;i>=0;i--){
    if(n-1-i>=20 && bst!=mdl+3)break;
    if(spsol[i]==-1)continue;
    in cloc=i;
    in cn=0;
    while(cloc<=n-1){
      cn*=2;
      cn+=(x[cloc]-'0');
      cn%=mdl;
      ++cloc;
    }
    cn+=spsol[i];
    cn%=mdl;
    bst=min(bst,cn);
  }
  cout<<bst%mdl<<endl;
  return 0;
}