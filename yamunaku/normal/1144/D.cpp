#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> count;
  for(int i=0;i<n;i++){
    cin >> a[i];
    count[a[i]]++;
  }
  int ans=0,num=0;
  for(auto p:count){
    if(p.second>ans){
      ans=p.second;
      num=p.first;
    }
  }
  cout << n-ans << endl;
  queue<int> q;
  vector<bool> usd(n,false);
  for(int i=0;i<n;i++){
    if(a[i]==num){
      usd[i]=true;
      q.push(i);
    }
  }
  while(!q.empty()){
    int now=q.front();
    q.pop();
    if(now<n-1) if(!usd[now+1]){
      cout << (a[now+1]<num?1:2) SP now+2 SP now+1 << endl;
      usd[now+1]=true;
      q.push(now+1);
    }
    if(now>0) if(!usd[now-1]){
      cout << (a[now-1]<num?1:2) SP now SP now+1 << endl;
      usd[now-1]=true;
      q.push(now-1);
    }
  }
  return 0;
}