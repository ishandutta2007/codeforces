#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

set<int> se;

char ch[1010][1010];
int N,M;

int get(int id){
	int s=-1,g=-1;
	for(int i=0;i<M;i++){
		if(ch[id][i]=='G') s=i;
		if(ch[id][i]=='S') g=i;
	}
	return g-s;
}


int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%s",ch[i]);
	for(int i=0;i<N;i++){
		int a=get(i);
		if(a<0){
			printf("-1\n");
			return 0;
		}
		se.insert(a);
	}
	printf("%d\n",(int)(se.size()));
	return 0;
}