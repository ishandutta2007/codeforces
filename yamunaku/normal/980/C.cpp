#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int main(){
  int n,k;
  cin >> n >> k;
  int p;
  vector<int> color(256,-1);
  int mae;
  for(int i=0;i<n;i++){
    cin >> p;
    if(color[p]==-1){
      mae=-1;
      for(int i=max(0,p-k+1);i<p;i++){
        mae=max(mae,color[i]);
      }
      if(mae==-1){
        for(int j=max(0,p-k+1);j<=p;j++) color[j]=max(0,p-k+1);
      }else{
        if(p-mae<k){
          for(int j=mae;j<=p;j++) color[j]=mae;
        }else{
          for(int j=mae;j<=p;j++){
            if(color[j]==-1){
              for(int l=j;l<=p;l++){
                color[l]=j;
              }
            }
          }
        }
      }
    }
    cout << color[p];
    if(i!=n-1){
      cout << " ";
    }else{
      cout << endl;
    }
  }
  return 0;
}