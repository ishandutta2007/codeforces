#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e6+5;
struct ele{
  int val,x,y;
  friend bool operator<(const ele&x,const ele&y){
    return x.val<y.val;
  }
}b[N]; 
int *a[N],*result[N];
set<int>col_num[N],row_num[N];
int col[N],row[N],n,m;
int id(int x,int y){return (x-1)*m+y;}

vector<int>tmp_col[N],tmp_row[N],qwq[N];
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}

int main(){
  scanf("%d%d",&n,&m);
  for(register int i=1;i<=n;i++){
    a[i]=new int[m+1];
    result[i]=new int[m+1];
    for(register int j=1;j<=m;j++){
      scanf("%d",&a[i][j]);
      b[id(i,j)]={a[i][j],i,j};
    }
  }
  stable_sort(b+1,b+n*m+1);
  /*
  for(register int i=1;i<=n*m;i++){
    printf("b[%d]=(%d,%d,%d)\n",i,b[i].val,b[i].x,b[i].y);
  }
  */
  int ans=0;
  for(register int i=1;i<=n*m;i++)f[i]=i;
  for(register int i=1;i<=n*m;i++){
    int j=i;
    while(j<n*m&&b[j+1].val==b[i].val)j++;
    //printf("solve %d %d\n",i,j);
    for(register int k=i;k<=j;k++){
      tmp_row[b[k].x].pb(k);
      tmp_col[b[k].y].pb(k);
    }
    for(register int k=i;k<=j;k++){
      if(!tmp_row[b[k].x].empty()){
        int anc=tmp_row[b[k].x][0];
        for(auto v:tmp_row[b[k].x]){
          merge(anc,v);
          //printf("row merge %d %d\n",anc,v);
        }
        tmp_row[b[k].x].clear();
      }
      if(!tmp_col[b[k].y].empty()){
        int anc=tmp_col[b[k].y][0];
        for(auto v:tmp_col[b[k].y]){
          //printf("col merge %d %d\n",anc,v);
          merge(anc,v);
        }
        tmp_col[b[k].y].clear();
      }
    }
    for(register int k=i;k<=j;k++)qwq[find(k)].pb(k);
    for(register int k=i;k<=j;k++){
      if(qwq[k].empty())continue;
      int least=-1;
      //printf(" >>> group: ");
      for(auto v:qwq[k]){
        //printf("%d ",v);
        least=max(least,max(row[b[v].x],col[b[v].y])+1);
      }
      //puts("");
      ans=max(ans,least);
      for(auto v:qwq[k]){
        row[b[v].x]=least;
        col[b[v].y]=least;
        result[b[v].x][b[v].y]=least;
      }
      qwq[k].clear();
    }
    i=j;
  }
  for(register int i=1;i<=n;i++){
    for(register int j=1;j<=m;j++){
      printf("%d ",result[i][j]);
    }
    puts("");
  }
  return 0;
}