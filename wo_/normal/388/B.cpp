#include<cstdio>

using namespace std;

bool G[100][100];
int a[30][2];

void getAll(){
	for(int i=0;i<100;i++) for(int j=0;j<100;j++) G[i][j]=false;
	G[1][3]=true;
	G[1][4]=true;
	G[1][61]=true;
	G[59][2]=true;
	G[60][2]=true;
	G[89][2]=true;
	for(int i=1;i<29;i++){
		int u=i*2+1,v=i*2+2;
		G[u][u+2]=true;
		G[u][v+2]=true;
		G[v][u+2]=true;
		G[v][v+2]=true;
	}
	for(int i=61;i<=88;i++){
		G[i][i+1]=true;
		int a=i-59;
		G[i][a*2+1]=true;
		G[i][a*2+2]=true;
	}
}

void putOff(int i){
	if(i==0){
		G[89][2]=false;
		return;
	}else if(i==29){
		G[1][3]=false;
		G[1][4]=false;
	}else{
		int v=89-i;
		int a=v-59;
		G[v][a*2+1]=false;
		G[v][a*2+2]=false;
	}
}

int main(){
	int K;
	scanf("%d",&K);
	getAll();
	for(int i=0;i<=29;i++){
		if(((K>>i)&1)==0){
			putOff(i);
		}
	}
	printf("89\n");
	for(int i=1;i<=89;i++){
		for(int j=1;j<=89;j++){
			if(G[i][j]||G[j][i]) printf("Y");
			else printf("N");
		}
		printf("\n");
	}
	return 0;
}