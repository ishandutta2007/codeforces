#include<stdio.h>
#include<string.h>

char A[100];
int len;

int main(){
	int i,j;
	scanf("%s",A);
	len=strlen(A);
	for(i=0;i<len;i++){
		if(A[i]!='1' && A[i]!='4')break;
	}
	if(i<len || A[0]!='1'){
		puts("NO");
		return 0;
	}
	for(i=0;i<len;i++){
		if(A[i]!='1')continue;
		for(j=i+1;j<len;j++){
			if(A[j]=='1')break;
		}
		if(j-i>3){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}