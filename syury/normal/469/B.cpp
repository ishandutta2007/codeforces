#include <stdio.h>

class pair{
public:
  int b,e;
};

pair z[50];
pair x[50];

bool can[1000];

int p,q,l,r,ans=0,cpos;

int main(){
  scanf("%d%d%d%d",&p,&q,&l,&r);
  for (int i=0;i<1000;i++){
    can[i]=false;
  }
  for (int i=0;i<p;i++){
    scanf("%d%d",&z[i].b,&z[i].e);
  }
  for (int i=0;i<q;i++){
    scanf("%d%d",&x[i].b,&x[i].e);
  }
  for (int i=0;i<p;i++){
    for (int j=0;j<q;j++){
      if ((z[i].b>x[j].b)&&(z[i].e>x[j].e)&&(z[i].b<x[j].e)){
	cpos=0;
	while ((x[j].b+cpos<=z[i].e)){
	  can[cpos]=true;
	  cpos++;
	}
      }
      if ((x[j].b>z[i].b)&&(x[j].e>z[i].e)&&(x[j].b<z[i].e)){
	cpos=0;
	while ((z[i].b+cpos<=x[j].e)){
	  can[cpos]=true;
	  cpos++;
	}
      }
      if (x[j].e<z[i].b){
	cpos=z[i].b-x[j].e;
	while (x[j].b+cpos<=z[i].e){
	  can[cpos]=true;
	  cpos++;
	}
      }
      if ((x[j].b==z[i].b)&&(x[j].e==z[i].e)){
	for (int k=0;k<=z[i].e-z[i].b;k++){
	  can[k]=true;
	}
      }
    }
  }
  for (int i=l;i<=r;i++){
    if (can[i]){ans++;}
  }
  printf("%d",ans);
  return 0;
}