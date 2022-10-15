#include<bits/stdc++.h>
using namespace std;
int cnt[105],n;
int check(int s){
  int ans=0;
  for(int i=1;i<=s/2;i++){
    if(2*i==s)ans+=cnt[i]/2;
    else ans+=min(cnt[i],cnt[s-i]);
  }
  return ans;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
      int x;
      scanf("%d",&x);
      cnt[x]++;
    }
    int ans=0;
    for(int s=1;s<=100;s++){
      ans=max(ans,check(s));
    }
    printf("%d\n",ans);
  }
  return 0;
}