#include<cstdio>
#include<queue>
#define N 200005

int n;
char s[N],t[N];

int cnt;

std::queue<int> q[2];

int main(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i++){
		if(s[i]!=t[i]){
			cnt++;
			if(s[i]=='a')
				q[0].push(i);
			else
				q[1].push(i);
		}
	}
	if(cnt&1){
		printf("-1");
		return 0;
	}
	printf("%d\n",(q[0].size()+q[1].size())/2+(q[0].size()&1));
	for(int opt=0;opt<2;opt++)
		while(q[opt].size()>1){
			int i=q[opt].front();
			q[opt].pop();
			int j=q[opt].front();
			q[opt].pop();
			printf("%d %d\n",i,j);
		}
	if(!q[0].empty()){
		int i=q[0].front(),j=q[1].front();
		printf("%d %d\n%d %d\n",i,i,i,j);
	}
}