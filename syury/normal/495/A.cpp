#include<stdio.h>

char a[2];
int b[2];
int ans;

int main(){
  a[0]=getc(stdin);
  a[1]=getc(stdin);
  for (int i=0;i<2;i++){
    switch(a[i]){
      case '0':b[i]=2;break;
      case '1':b[i]=7;break;
      case '2':b[i]=2;break;
      case '3':b[i]=3;break;
      case '4':b[i]=3;break;
      case '5':b[i]=4;break;
      case '6':b[i]=2;break;
      case '7':b[i]=5;break;
      case '8':b[i]=1;break;
      case '9':b[i]=2;break;
    }
  }
  ans=b[0]*b[1];
  printf("%d",ans);
  return 0;
}