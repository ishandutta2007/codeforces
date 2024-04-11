#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

typedef list<pair<int,int> >::iterator iter;

int n,m,left=0;;
char field[2000][2000];
int d[2000][2000];
queue<pair<int,int> >q;

void modify(int x,int y){
    if(x>0){d[x-1][y]--;if((d[x-1][y]==1)&&(field[x-1][y]=='.')){q.push(make_pair(x-1,y));}}
    if(x<n-1){d[x+1][y]--;if((d[x+1][y]==1)&&(field[x+1][y]=='.')){q.push(make_pair(x+1,y));}}
    if(y>0){d[x][y-1]--;if((d[x][y-1]==1)&&(field[x][y-1]=='.')){q.push(make_pair(x,y-1));}}
    if(y<m-1){d[x][y+1]--;if((d[x][y+1]==1)&&(field[x][y+1]=='.')){q.push(make_pair(x,y+1));}}
}

void remove(int x,int y){
    if((x>0)&&(field[x-1][y]=='.')){field[x][y]='v';field[x-1][y]='^';modify(x-1,y);}
    if((x<n-1)&&(field[x+1][y]=='.')){field[x][y]='^';field[x+1][y]='v';modify(x+1,y);}
    if((y>0)&&(field[x][y-1]=='.')){field[x][y]='>';field[x][y-1]='<';modify(x,y-1);}
    if((y<m-1)&&(field[x][y+1]=='.')){field[x][y]='<';field[x][y+1]='>';modify(x,y+1);}
    modify(x,y);
}

int main(){
  scanf("%d%d",&n,&m);getc(stdin);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      field[i][j]=getc(stdin);d[i][j]=0;
      if(field[i][j]=='.'){left++;}
    }
    getc(stdin);
  }
  for (int x=0;x<n;x++){
    for (int y=0;y<m;y++){
    if((x>0)&&(field[x-1][y]=='.')){d[x][y]++;}
    if((x<n-1)&&(field[x+1][y]=='.')){d[x][y]++;}
    if((y>0)&&(field[x][y-1]=='.')){d[x][y]++;}
    if((y<m-1)&&(field[x][y+1]=='.')){d[x][y]++;}
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if((d[i][j]==1)&&(field[i][j]=='.')){q.push(make_pair(i,j));}
    }
  }
  while(!q.empty()){
    int x=q.front().first,y=q.front().second;
    if((d[x][y]==1)&&(field[x][y]=='.')){remove(x,y);left-=2;}
    q.pop();
  }
  if(left!=0){printf("Not unique");}
  else{
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
	putc(field[i][j],stdout);
      }
      printf("\n");
    }
  }
  return 0;
}