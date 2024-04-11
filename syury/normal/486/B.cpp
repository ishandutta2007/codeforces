#include <stdio.h>
#include <stdlib.h>

int b[100][100];
int n,m;
int a[100][100];
int tmp[2][100];
int mid;

int main(){
  scanf("%d%d",&m,&n);
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      scanf("%d",&b[i][j]);
      a[i][j]=1;
    }
  }
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      if (b[i][j]==0){
	for (int k=0;k<n;k++){a[i][k]=0;}
	for (int k=0;k<m;k++){a[k][j]=0;}
      }
    }
  }
  for (int i=0;i<m;i++){
    mid=0;
    for (int j=0;j<n;j++){
      mid+=a[i][j];
    }
    if (mid==0){tmp[0][i]=0;}else{tmp[0][i]=1;}
  }
  for (int j=0;j<n;j++){
    mid=0;
    for (int i=0;i<m;i++){
      mid+=a[i][j];
    }
    if (mid==0){tmp[1][j]=0;}else{tmp[1][j]=1;}
  }
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      if ((tmp[0][i]||tmp[1][j])!=b[i][j]){printf("NO\n");exit(0);}
    }
  }
  printf("YES\n");
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}