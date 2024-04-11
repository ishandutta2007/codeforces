#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> >pv,kv;
vector<int> ev,ov;

int n,k,p;

int main(){
  scanf("%d%d%d",&n,&k,&p);
  for (int i=0;i<n;i++){
    int tmp;
    scanf("%d",&tmp);
    if(tmp%2==0){ev.push_back(tmp);}else{ov.push_back(tmp);}
  }
  if(ov.size()<k-p){printf("NO");return 0;}
  int ptr=0;
  for (int i=0;i<k-p;i++){
    vector<int>tmp(1,ov[ptr]);
    kv.push_back(tmp);
    ptr++;
  }
  int ptr2=0;
  for (int i=0;i<p;i++){
        if(ptr2>=ev.size()){break;}
    vector<int>tmp(1,ev[ptr2]);
    pv.push_back(tmp);
    ptr2++;

  }
  while(ptr2<ev.size()){
    if(p>0){pv[0].push_back(ev[ptr2]);}else{kv[0].push_back(ev[ptr2]);}
    ptr2++;
  }
  if((ov.size()-ptr)%2==1){printf("NO");return 0;}
  while((ptr<ov.size())&&(pv.size()<p)){
    vector<int>tmp(2);
    tmp[0]=ov[ptr];ptr++;
    if(ptr>=ov.size()){break;}
    tmp[1]=ov[ptr];ptr++;
    pv.push_back(tmp);
  }
  if(pv.size()<p){printf("NO");return 0;}
    while(ptr<ov.size()){
    if(p>0){pv[0].push_back(ov[ptr]);}else{kv[0].push_back(ov[ptr]);}
    ptr++;
  }
  printf("YES\n");
  for (int i=0;i<pv.size();i++){
    printf("%d ",pv[i].size());
    for (int j=0;j<pv[i].size();j++){
      printf("%d ",pv[i][j]);
    }
    printf("\n");
  }
   for (int i=0;i<kv.size();i++){
    printf("%d ",kv[i].size());
    for (int j=0;j<kv[i].size();j++){
      printf("%d ",kv[i][j]);
    }
    printf("\n");
  }
  return 0;
}