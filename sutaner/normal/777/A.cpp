#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 10
using namespace std;
int game[maxn][3];
int n,x;
void init(){
	game[0][0]=0,game[0][1]=1,game[0][2]=2;
	for(int i=1;i<=6;i++){
		if(i&1){
			game[i][0]=game[i-1][1];
			game[i][1]=game[i-1][0];
			game[i][2]=game[i-1][2];
		}
		else{
			game[i][2]=game[i-1][1];
			game[i][1]=game[i-1][2];
			game[i][0]=game[i-1][0];
		}
	}
	n=n%6;
	if(n==0)n=6;
	printf("%d",game[n][x]);
	return;
}

int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d%d",&n,&x);
	init();
	return 0;
}