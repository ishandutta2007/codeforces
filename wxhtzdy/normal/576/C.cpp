#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
  int n;
  scanf("%i",&n);
  vector<pair<int,int>> a[1010];
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%i%i",&x,&y);
    a[x/1000].pb({y,i});
  }
  for(int i=0;i<=1000;i++){
    sort(a[i].begin(),a[i].end());
    if(i%2==1)reverse(a[i].begin(),a[i].end());
    for(int j=0;j<(int)a[i].size();j++)printf("%i ",a[i][j].second+1);
  }
}