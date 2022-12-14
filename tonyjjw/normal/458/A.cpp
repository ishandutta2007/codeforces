#include<stdio.h>
#include<string.h>
#define MN 100010
//#pragma warning(disable:4996)

int L1,L2,A1[MN],A2[MN];
char str1[MN+1],str2[MN+1];

int main(){
	int i;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%s%s",str1,str2);
	L1=strlen(str1),L2=strlen(str2);
	for(i=L1-1;i>=0;i--){
		A1[MN-1-(L1-1-i)]=str1[i]-'0';
	}
	for(i=L2-1;i>=0;i--){
		A2[MN-1-(L2-1-i)]=str2[i]-'0';
	}
	for(i=3;i<MN-1;i++){
		if(A1[i] && A1[i+1]){
			A1[i-1]=1;
			A1[i]=A1[i+1]=0;
			i=i-3;
			continue;
		}
	}
	for(i=3;i<MN-1;i++){
		if(A2[i] && A2[i+1]){
			A2[i-1]=1;
			A2[i]=A2[i+1]=0;
			i=i-3;
			continue;
		}
	}
	for(i=0;i<MN;i++){
		if(A1[i]!=A2[i])break;
	}
	if(i==MN){
		puts("=");
		return 0;
	}
	if(A1[i]==1){
		puts(">");
		return 0;
	}
	puts("<");
	return 0;
}