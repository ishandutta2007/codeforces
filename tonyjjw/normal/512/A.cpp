//*
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#define MN 100
#define ML 100
#define AN 26

int N;
char str[MN][ML+1];
int L[MN];
int E[AN][AN];
int chk[AN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;i++)scanf("%s",str[i]),L[i]=strlen(str[i]);
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			for(k=0;;k++){
				if(k==L[i] || k==L[j])break;
				if(str[i][k]!=str[j][k])break;
			}
			if(k==L[j]){
				puts("Impossible");
				return 0;
			}
			if(k==L[i])continue;
			E[str[i][k]-'a'][str[j][k]-'a']=1;
		}
	}
	for(k=0;k<AN;k++){
		for(i=0;i<AN;i++){
			for(j=0;j<AN;j++){
				if(k==i || k==j || i==j)continue;
				if(E[i][k]&&E[k][j])E[i][j]=1;
			}
		}
	}
	for(i=0;i<AN;i++){
		for(j=0;j<AN;j++){
			if(E[i][j]&&E[j][i]){
				puts("Impossible");
				return 0;
			}
		}
	}
	for(i=0;i<AN;i++){
		for(j=0;j<AN;j++){
			if(chk[j])continue;
			for(k=0;k<AN;k++){
				if(!chk[k] && E[k][j])break;
			}
			if(k==AN)break;
		}
		chk[j]=1;
		printf("%c",'a'+j);
	}
	return 0;
}
//*/