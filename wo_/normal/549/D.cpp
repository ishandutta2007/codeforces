#include<cstdio>
#include<algorithm>

using namespace std;

char ch[110][110];
int N,M;

int num[110][110];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%s",ch[i]);
	int res=1;
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) num[i][j]=ch[i][j]==ch[N-1][M-1]?0:1;
	for(int i=N-1;i>=0;i--) for(int j=M-1;j>=0;j--){
		if(num[i][j]!=0){
			++res;
			int v=num[i][j];
			for(int k=0;k<=i;k++) for(int l=0;l<=j;l++){
				num[k][l]-=v;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}