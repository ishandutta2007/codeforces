#include <stdio.h>
#include <utility>
#include <stdlib.h>

#define program_end exit(0)

using namespace std;

int a[6];

void qsort(int l,int r){
  int tmp = a[l+1];
  int i=l;
  int j=r;
  int tmr;
  while (i<=j){
    while (a[i]<tmp){i++;}
    while (a[j]>tmp){j--;}
    if (i<=j){tmr=a[i];a[i]=a[j];a[j]=tmr;i++;j--;}
  }
  if (i<r){qsort(i,r);}
  if (j>l){qsort(l,j);}
}

pair<int,int> eq(){
  pair<int,int> res;
  if (a[0]==a[1] && a[1]==a[2] && a[2]==a[3]){return make_pair(a[4],a[5]);}
  if (a[1]==a[2] && a[2]==a[3] && a[3]==a[4]){return make_pair(a[0],a[5]);}
  if (a[2]==a[3] && a[3]==a[4] && a[4]==a[5]){return make_pair(a[0],a[1]);}
  return make_pair(-1,-1);
}

int main(){
  for (int i=0;i<6;i++){
    scanf("%d",&a[i]);
  }
  qsort(0,5);
  pair<int,int> res = eq();
  if (res.first == -1){printf("Alien");program_end;}
  if (res.first == res.second){printf("Elephant");}else{printf("Bear");}
  return 0;
}