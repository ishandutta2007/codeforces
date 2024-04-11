#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
  int n;
  scanf("%i",&n);
  vector<pair<int,int>> c;
  for(int i=0;i<n;i++){
    int l,r;
    scanf("%i%i",&l,&r);
    c.pb({l,0});c.pb({r,1});
  }
  int cnt=0,mk=0;
  sort(c.begin(),c.end());
  for(int i=0;i<2*n;i++){
    if(c[i].second==0)cnt++;
    else cnt--;
    if(cnt>=3){printf("NO");return 0;}
  }
  printf("YES");
}