
//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 500 + 10;

int N,M;
char map[MN][MN];
int s1[MN][MN];
int s2[MN][MN];

int getval(int s[MN][MN],int r1,int c1,int r2,int c2){
	return s[r2][c2] - s[r2][c1-1] - s[r1-1][c2] + s[r1-1][c1-1];
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%s",map[i]+1);
	}
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
		if(i>1 && map[i][j]=='.' && map[i-1][j]=='.')s1[i][j]=1;
		if(j>1 && map[i][j]=='.' && map[i][j-1]=='.')s2[i][j]=1;
	}
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
		s1[i][j] += s1[i][j-1];
		s2[i][j] += s2[i][j-1];
	}
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
		s1[i][j] += s1[i-1][j];
		s2[i][j] += s2[i-1][j];
	}
	int Q;
	scanf("%d",&Q);
	for(int q=0;q<Q;q++){
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int v1 = getval(s1,r1+1,c1,r2,c2);
		int v2 = getval(s2,r1,c1+1,r2,c2);
		printf("%d\n",v1+v2);
	}
	return 0;
}

//*/