#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=1000007;

bool vis[maxn];
int ans[maxn];
int cnt=0;

void make_set(int n){
	for (int i=2;i<=n;++i){
		if (!vis[i]){
			cnt++;
			for (int j=1;i*j<=n;++j){
				vis[i*j]=1;
				ans[i*j]=cnt;
			}
		}
	}
}

int main(){
	memset(vis,0,sizeof(vis));
	int n;
	scanf("%d",&n);
	make_set(n);
	for (int i=2;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}