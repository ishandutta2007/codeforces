#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn2 15
using namespace std;
char name[5][maxn2];
int n,con=0;

void print(){
	printf("%s %s\n",name[0],name[1]);
	return;
}

int judge(){
	if(strcmp(name[0],name[2])==0)return 0;
	else return 1;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%s %s\n",&name[0],&name[1]);
	print();
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s\n",&name[2],&name[3]);
		int k=judge();
		strcpy(name[k],name[3]);
		print();
	}
	return 0;
}