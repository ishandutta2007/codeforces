#include<cstdio>

using namespace std;

int a[100100];
int N,t;

int main(){
	scanf("%d%d",&N,&t);
	for(int i=1;i<N;i++) scanf("%d",a+i);
	int p=1;
	while(true){
		if(p==t){
			printf("YES\n");
			return 0;
		}
		if(p==N) break;
		p+=a[p];
	}
	printf("NO\n");
	return 0;
}