#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> >ans;
int n;
vector<int>t;

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  ans.resize(n);
  t.resize(n);
  for (int i=0;i<n;i++){
    ans[i].resize(2);
    scanf("%d",&t[i]);
  }
  ans[0][1]=1000000000;
  ans[0][0] = (t[0]<0)? 0:1;
  for (int i=1;i<n;i++){
    ans[i][1]=min(ans[i-1][1],ans[i-1][0]);if(t[i]<=0){ans[i][1]++;}//printf("Ans[%d,1]: %d\n",i,ans[i][1]);
    ans[i][0]=ans[i-1][0];if(t[i]>=0){ans[i][0]++;}//printf("Ans[%d,0]: %d\n",i,ans[i][0]);
  }
  printf("%d",ans[n-1][1]);
  return 0;
}