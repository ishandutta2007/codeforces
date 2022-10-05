#include<bits/stdc++.h>
using namespace std;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int x=0;
		for(int i=0;i<29;i++){
			printf("? %d %d\n",(1<<(i+1))-x,(1<<(i+2))-x);
			fflush(stdout);
			int y;
			scanf("%d",&y);
			if(y==(1<<i))x+=(1<<i);
		}
		printf("? %d %d\n",3-x%3,6-x%3);
		fflush(stdout);
		int y;
		scanf("%d",&y);
		if(y==1)x+=(1<<29);
		printf("! %d\n",x);
		fflush(stdout);
	}
	return 0; 
}