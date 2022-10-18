/*
 
| _ _|
 ` _x 
  /  |
 /  c ?
| |||
| (c_c_)_)

*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N (1<<18)

int n;

int cnt[N];

inline int rnd(){
	return (rand()<<15)|rand();
}

int main(){
	srand(114514);
	scanf("%d",&n);
	n=(1<<n)-1;
	for(int i=1;i<=422;i++){
		int u=rnd()%n+1,v=rnd()%n+1,w=rnd()%n+1;
		while(v==u)
			v=rnd()%n+1;
		while(w==v||w==u)
			w=rnd()%n+1;
		printf("? %d %d %d\n",u,v,w);
		fflush(stdout);
		int tmp;
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	int u=0,v=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]>cnt[u]){
			v=u;
			u=i;
		}
		else if(cnt[i]>cnt[v])
			v=i;
	}
	for(int i=1;i<=n;i++)
		if(i!=u&&i!=v){
			printf("? %d %d %d\n",u,v,i);
			fflush(stdout);
			int tmp;
			scanf("%d",&tmp);
			if(tmp==i){
				printf("! %d\n",tmp);
				break;
			}
		}
}