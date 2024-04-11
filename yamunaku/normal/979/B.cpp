#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  string ribbon[3];
  cin >> ribbon[0] >> ribbon[1] >> ribbon[2];
  int count[3][100];
  for(int i=0;i<3;i++){
    for(int j=0;j<100;j++){
      count[i][j]=0;
    }
  }
  int max[3]={0,0,0};
  int point[3];
  for(int i=0;i<3;i++){
    for(int j=0;j<ribbon[i].length();j++){
      count[i][ribbon[i][j]-'A']++;
    }
    for(int j=0;j<100;j++){
      max[i]=max(max[i],count[i][j]);
    }
    if(n==1){
      if(max[i]==ribbon[i].length()){
        point[i]=ribbon[i].length()-1;
      }else{
        point[i]=max[i]+1;
      }
      continue;
    }
    point[i]=min(max[i]+n,ribbon[i].length());
  }
  if(point[0]>point[1]){
    if(point[0]>point[2]){
      cout << "Kuro" << endl;
      return 0;
    }else if(point[2]>point[0]){
      cout << "Katie" << endl;
      return 0;
    }
  }else if(point[1]>point[0]){
    if(point[1]>point[2]){
      cout << "Shiro" << endl;
      return 0;
    }else if(point[2]>point[1]){
      cout << "Katie" << endl;
      return 0;
    }
  }else if(point[2]>point[0]){
    cout << "Katie" << endl;
    return 0;
  }
  cout << "Draw" << endl;
  return 0;
}