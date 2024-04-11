//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 500+1;
int A[MN][MN];
int N,M;
char color[MN];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b),--a,--b;
		A[a][b]=A[b][a]=1;
	}
	for(int i=0;i<N;i++){
		bool isb=true;
		for(int j=0;j<N;j++){
			if(i!=j && A[i][j]==0)isb=false;
		}
		if(isb){
			color[i]='b';
			continue;
		}
		color[i]='a';
		for(int j=0;j<i;j++){
			if(A[i][j]==0){
				if(color[j]=='a'){
					color[i]='c';
				}
				else{
					color[i]='a';
				}
			}
			if(A[i][j]==1){
				if(color[j]=='a'){
					color[i]='a';
				}
				else if(color[j]=='c'){
					color[i]='c';
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(A[i][j]==0){
				if(color[i]=='a' && color[j]=='c'){
				}
				else if(color[i]=='c' && color[j]=='a'){
				}
				else{
					puts("No");
					return 0;
				}
			}
			else{
				if(color[i]=='a' && color[j]=='c'){
					puts("No");
					return 0;
				}
				else if(color[i]=='c' && color[j]=='a'){
					puts("No");
					return 0;
				}
			}
		}
	}
	puts("Yes");
	printf("%s",color);
	return 0;
}

//*/