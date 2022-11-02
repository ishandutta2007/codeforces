#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<stdlib.h>

using namespace std;

vector<pair<int,int> >a;
int n,m;
int ans;

int main(){
  scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++){
    int tmp1,tmp2;
    scanf("%d%d",&tmp1,&tmp2);
    a.push_back(make_pair(tmp1,tmp2));
  }
  ans=max(a[m-1].second+(n-a[m-1].first),a[0].second+a[0].first-1);
  for (int i=0;i<m-1;i++){
    ans=max(a[i].second,ans);
    int d=abs(a[i+1].second-a[i].second);
    if(d>(a[i+1].first-a[i].first)){printf("IMPOSSIBLE");return 0;}
    int x=a[i].second,y=a[i+1].second,d1=a[i].first,d2=a[i+1].first;
    int dl=(abs(y-x)+d2-d1)/2;
    ans=max(ans,min(x,y)+dl);
  }
  printf("%d",ans);
  return 0;
}