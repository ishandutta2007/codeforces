#include<cstdio>
#define N 200005

int n;

int pos[N];

struct edge{
	int pre,nxt;
}e[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		pos[a]=i;
		e[i]=(edge){i-1,i+1};
	}
	for(int i=n;i>1;i--){
		if(e[pos[i]].nxt==pos[i-1]){
			e[e[pos[i]].pre].nxt=pos[i-1];
			e[pos[i-1]].pre=e[pos[i]].pre;
		}
		else if(e[pos[i]].pre==pos[i-1]){
			e[e[pos[i]].nxt].pre=pos[i-1];
			e[pos[i-1]].nxt=e[pos[i]].nxt;
		}
		else{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}