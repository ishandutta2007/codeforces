#include<stdio.h>
char *d="Bulbasaur";
char in[100010];
int min(int a, int b){ return a>b?b:a; }
int min(int a, int b, int c){ return min(a, min(b, c)); }
int main(){
	int x=0, n, B=0, u=0, l=0, b=0, a=0, s=0, r=0;
	scanf("%s", in);
	for(int i=0; in[i]; i++){
		if(in[i] == 'B')B++;
		if(in[i] == 'l')l++;
		if(in[i] == 'b')b++;
		if(in[i] == 'u')u++;
		if(in[i] == 'a')a++;
		if(in[i] == 's')s++;
		if(in[i] == 'r')r++;
	}
	printf("%d", min(min(B, u/2, l), min(b, a/2, s), r));
	return 0;
}