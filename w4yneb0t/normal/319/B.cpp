#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cassert>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef map<int,int>::iterator mit;
struct eg{
  int l, t;
};
int mar[100009];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>mar[i];
  }
  map<int,int> mm;
  int r=0;
  eg teg;
  queue<eg> q;
  for(int i=n-1;i>=0;i--){
    mm[i]=mar[i];
    if(i!=n-1 && mar[i+1]<mar[i]){
      teg.l=i;
      teg.t=0;
      q.push(teg);
    }
  }
  while(!q.empty()){
    teg=q.front();
    q.pop();
    int l=teg.l;
    int t=teg.t;
    mit it=mm.find(l);
    if(it==mm.end())
      continue;
    if(t+1>r)
      r=t+1;
    int w=it->second;
    ++it;
    ++it;
    int w2;
    if(it!=mm.end())
      w2=it->second;
    else
      w2=n+2;
    it=mm.find(l);
    ++it;
    /*bool debug=true;
    cout<<l<<" "<<w<<" "<<it->first<<" "<<it->second<<endl;
    if(it->second==8)
      cout<<"wut"<<endl;*/
    mm.erase(it->first);
    if(w2<w){
      teg.t++;
      q.push(teg);
    }
  }
  cout<<r<<endl;
  return 0;
}