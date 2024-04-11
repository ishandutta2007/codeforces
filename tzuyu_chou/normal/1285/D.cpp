#include<bits/stdc++.h>
//#include <vector>
//#include <iostream>

using namespace std;
 
#define ll long long
#define ar array
 
#define fi first
#define se second

int solve(vector<int>a,int bits){
  if (bits==-1||a.empty()){
    return 0;
  }
  vector<int>l,r;
  for(int i=0;i<(int)a.size();i++){
    if((a[i]>>bits)&1){
      l.push_back(a[i]);
    }else{
      r.push_back(a[i]);
    }
  }
  if(l.empty()||r.empty()){
    if (!l.empty()) return solve(l,bits-1);
    else return solve(r,bits-1);
  } else {
    return min(solve(l,bits-1),solve(r,bits-1))+(1<<bits);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  cout<<solve(a,29) << endl;
}