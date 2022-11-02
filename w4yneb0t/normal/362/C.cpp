#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;
in pm[5009];
in n;
in invs;
int bl[5009][5009];
int main(){
  cin>>n;
  for(in i=0;i<n;i++){
    cin>>pm[i];
    pm[i]++;
    bl[i][pm[i]]++;
  }
  for(in i=0;i<n;i++){
    in ct=0;
    for(in j=0;j<=n;j++){
      ct+=bl[i][j];
      bl[i][j]=ct;
    }
  }
  for(in j=0;j<=n;j++){
    in ct=0;
    for(in i=0;i<n;i++){
      ct+=bl[i][j];
      bl[i][j]=ct;
    }
  }
  invs=0;
  in bt=-1;
  in ct=0;
  in d;
  for(in i=0;i<n;i++)
    for(in j=i+1;j<n;j++)
      if(pm[i]>pm[j]){
        invs++;
        d=bl[j][pm[i]]-bl[i][pm[i]]-bl[j][pm[j]]+bl[i][pm[j]];
        if(d==bt){
          ct++;
        }
        if(d>bt){
          bt=d;
          ct=1;
        }
      }
  cout<<invs-(1+2*bt)<<" "<<ct<<endl;
  return 0;
}