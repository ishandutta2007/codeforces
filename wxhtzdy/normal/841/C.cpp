#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%i",&n);
  int a[n],b[n];
  for(int i=0;i<n;i++)scanf("%i",&a[i]);
  for(int i=0;i<n;i++)scanf("%i",&b[i]);
  vector<pair<int,int>> b1(n);
  for(int i=0;i<n;i++){
    b1[i].first=b[i];
    b1[i].second=i;
  }
  sort(b1.begin(), b1.end());
  sort(a,a+n); reverse(a,a+n);
  int ans[n];
  for(int i=0;i<n;i++)ans[b1[i].second]=a[i];
  for(int i=0;i<n;i++)printf("%i ",ans[i]);
}