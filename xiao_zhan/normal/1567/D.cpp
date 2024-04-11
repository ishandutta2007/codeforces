#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,it,res,p[15]={1};

void get(int x,int y){
	if(y==1){
		printf("%d\n",x);return;
	}
	for(int i=9;i>=0;i--){
		if(x<p[i]){continue;}
		if(x-p[i]<y-1){
			continue;
		}
		printf("%d ",p[i]);
		get(x-p[i],y-1);
		return;
	}
}

int main(){
	for(i=1;i<=9;i++){
		p[i]=p[i-1]*10;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		res=0;
		get(n,m);
	}
}