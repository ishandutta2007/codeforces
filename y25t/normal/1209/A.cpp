#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 105

int n,a[N];

bool vis[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++){
		int tmp=inf;
		bool flg=0;
		for(int j=1;j<=n;j++)
			if(!vis[j])
				tmp=std::min(tmp,a[j]);
		for(int j=1;j<=n;j++)
			if(a[j]%tmp==0&&!vis[j]){
				flg=1;
				vis[j]=1;
			}
		if(!flg){
			printf("%d",i-1);
			break;
		}
	}
}