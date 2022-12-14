#include<cstdio>
#include<algorithm>

using namespace std;

int N,W;
int a[200200],b[200200];

int fail[200200];

void buildFail(int *a,int N,int *fail){
	int j=-1;
	fail[0]=j;
	for(int i=1;i<=N;i++){
		while(j>=0&&a[j]!=a[i-1]) j=fail[j];
		j++;
		fail[i]=j;
	}
}

int match(int *t,int N,int *p,int W,int *fail){
	int res=0;
	int i=0,k=0;
	for(;i<N;i++){
		while(k>=0&&p[k]!=t[i]) k=fail[k];
		k++;
		if(k>=W){
			res++;
			k=fail[k];
		}
	}
	return res;
}

int main(){
	scanf("%d%d",&N,&W);
	if(W==1){
		printf("%d\n",N);
		return 0;
	}else if(N<W){
		printf("0\n");
		return 0;
	}
	int prev;
	scanf("%d",&prev);
	for(int i=0;i<N-1;i++){
		int in;
		scanf("%d",&in);
		a[i]=in-prev;
		prev=in;
	}
	scanf("%d",&prev);
	for(int i=0;i<W-1;i++){
		int in;
		scanf("%d",&in);
		b[i]=in-prev;
		prev=in;
	}
	N--;
	W--;
	buildFail(b,W,fail);
	int ans=match(a,N,b,W,fail);
	printf("%d\n",ans);
	return 0;
}