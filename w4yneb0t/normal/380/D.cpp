#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
in pw2[100009];
in fct[100009];
in fctinv[100009];
in mdl=1000000007LL;
in n;
in inv(in a){
  in pw=mdl-2;
  in r=1;
  for(in i=35;i>=0;i--){
    r*=r;
    r%=mdl;
    if(pw&(1LL<<i)){
      r*=a;
      r%=mdl;
    }
  }
  return r;
}
in ncr(in a, in b){
  return (((fct[a]*fctinv[b])%mdl)*fctinv[a-b])%mdl;
}
in mar[100009];
in lof[100009];
in cust[100009];
in tar[100009];
in htd(in ar[]){
  forn(i,n)
    lof[i]=-1;
  forn(i,n){
    if(ar[i]>=0)
      lof[ar[i]]=i;
  }
  in fst=-1;
  forn(i,n){
    if(lof[i]!=-1){
      fst=i;
      break;
    }
  }
  in left,right;
  in curws=1;
  if(fst>0)
    curws=pw2[fst-1];
  right=lof[fst];
  left=right-fst;
  in ltp=fst;
  in cloc=right-1;
  ar[right]=-2;
  while(ltp>0){
    if(cloc<0 || ar[cloc]!=-1){
      return 0;
    }
    ar[cloc]=-2;
    ltp--;
    cloc--;
  }
  while(1){
    in nxt=fst+1;
    while(nxt<n && lof[nxt]==-1)
      nxt++;
    if(nxt==n){
      curws*=ncr(n-(right-left+1),left);
      curws%=mdl;
      return curws;
    }
    in nr,nl;
    if(lof[nxt]>right){
      nr=lof[nxt];
      nl=nr-nxt;
      if(nl<0)
	return 0;
    }
    else{
      nl=lof[nxt];
      nr=nl+nxt;
      if(nr>=n)
	return 0;
    }
    ar[lof[nxt]]=-1;
    for(in i=right+1;i<=nr;i++){
      if(ar[i]!=-1)
	return 0;
      ar[i]=-2;
    }
    for(in i=nl;i<left;i++){
      if(ar[i]!=-1)
	return 0;
      ar[i]=-2;
    }
    if(lof[nxt]<left)
      curws*=ncr(nr-nl+1-(right-left+1)-1,left-nl-1);
    else
      curws*=ncr(nr-nl+1-(right-left+1)-1,left-nl);
    curws%=mdl;
    //cout<<left<<" "<<right<<" "<<nl<<" "<<nr<<" "<<nxt<<" "<<lof[nxt]<<endl;
    fst=nxt;
    right=nr;
    left=nl;
  }
  return curws;
}
int main(){
  pw2[0]=1;
  for(in i=1;i<100009;i++){
    pw2[i]=(pw2[i-1]*2)%mdl;
  }
  fct[0]=1;
  for(in i=1;i<100009;i++){
    fct[i]=(fct[i-1]*i)%mdl;
  }
  forn(i,100009)
    fctinv[i]=inv(fct[i]);
  in totw=0;
  cin>>n;
  forn(i,n)
    lof[i]=-1;
  forn(i,n){
    cin>>mar[i];
    mar[i]--;
    if(mar[i]>=0)
      lof[mar[i]]=i;
  }
  in fst=-1;
  forn(i,n){
    if(lof[i]!=-1){
      fst=i;
      break;
    }
  }
  if(fst==-1){
    cout<<pw2[n-1]<<endl;
    return 0;
  }
  forn(i,n)
    tar[i]=mar[i];
  totw+=htd(tar);
  if(fst!=0){
    reverse(mar,mar+n);
    totw+=htd(mar);
  }
  totw%=mdl;
  cout<<totw<<endl;
  return 0;
}