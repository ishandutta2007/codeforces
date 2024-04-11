#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	if (x>y-2&&(x-y)%2&&(y>1||(y==1&&x==0))){
		printf("Yes");
	} 
	else{
		printf("No");
	}
}