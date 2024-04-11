#include<cstdio>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	if(N%2==0){
		printf("%d %d\n",4,N-4);
	}else{
		printf("%d %d\n",9,N-9);
	}
	return 0;
}