#include <bits/stdc++.h>

#define FOR(i,n) for(int i =0;i<n;i++)
#define ll long long int
#define vi vector<int>

using namespace std;

string transform(string s1){
  string ss1="";
  FOR(i,s1.length()){
    if(s1[i]=='u')ss1+="oo";
    else ss1 += s1[i];
  }
  string sss1="";
  string temp = "";
  FOR(i,ss1.length()){
    if(ss1[i]=='k')temp+="k";
    else if(ss1[i]=='h')temp="",sss1+="h";
    else sss1 += temp +ss1[i],temp ="";
  }
  if(temp!="")sss1+=temp;
  return sss1;
}

bool eq(string s1,string s2)
{

 return transform(s1) == transform(s2);
}

int main(){
  int n;
  cin >> n;
  string arr[n];
  FOR(i,n)cin >> arr[i];
  //.//OR(i,n)cout<<transform(arr[i])<<endl;
  FOR(i,n)arr[i] = transform(arr[i]);
  sort(arr,arr+n);
  int ctr = 1;
  FOR(i,n){
    if(i==0)continue;
    if(arr[i]!=arr[i-1])ctr++;
  }
  cout<<ctr<<endl;
  return 0;
}