#include<cstdio>

int T;

int n,k;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(k%3)
			if(n%3)
				printf("Alice\n");
			else
				printf("Bob\n");
		else{
			int tmp=n%(k+1);
			if(tmp%3||tmp==k)
				printf("Alice\n");
			else
				printf("Bob\n");
		}
	}
}