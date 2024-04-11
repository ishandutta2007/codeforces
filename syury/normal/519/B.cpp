#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>

using namespace std;

int n;
map<int,int>err1,err2,err3;
vector<int>a;

int main(){
  scanf("%d",&n);a.resize(n);
  for (int i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(!err1.count(a[i])){err1.insert(make_pair(a[i],1));err2.insert(make_pair(a[i],0));err3.insert(make_pair(a[i],0));}else{err1[a[i]]++;}
  }
  int tmp;
  for (int i=0;i<n-1;i++){
    scanf("%d",&tmp);
    err2[tmp]++;
  }
  for (int i=0;i<n;i++){
    if(err1[a[i]]!=err2[a[i]]){tmp=a[i];}
  }
  printf("%d\n",tmp);
  for (int i=0;i<n-2;i++){
    scanf("%d",&tmp);
    err3[tmp]++;
  }
  for (int i=0;i<n;i++){
    if(err3[a[i]]!=err2[a[i]]){tmp=a[i];}
  }
  printf("%d\n",tmp);
  return 0;
}