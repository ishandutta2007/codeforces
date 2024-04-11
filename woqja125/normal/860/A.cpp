#include<stdio.h>
char x[3100];
int dp[3010];
int p[3010];

int main(){
	scanf("%s", x);
	int a=0, b=0, c=0;
	for(int i=0; x[i]; i++){
		if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u'){
			a=b=c=0;
			printf("%c", x[i]);
			continue;
		}
		a++;
		if((c&(1<<(x[i]-'a'))) == 0){
			b++;
			c |= (1<<(x[i]-'a'));
		}
		if(a>=3 && b>=2){
			a=b=1;
			c = 1<<(x[i]-'a');
			printf(" %c", x[i]);
		}
		else printf("%c", x[i]);
	}
	printf("\n");
	return 0;
}