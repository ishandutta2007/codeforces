#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 2007;

char map[maxn][maxn];
int n,m,k;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;++i){
		scanf("%s",map[i]);
	}
	int ans=0;
	for (int i=0;i<n;++i){
		int cnt=0;
		for (int j=0;j<m;++j){
			if (map[i][j]=='.'){
				cnt++;
			}
			else{
				ans+=max(cnt-k+1,0);
				cnt=0;
			}
		}
		ans+=max(cnt-k+1,0);
	}
	for (int j=0;j<m;++j){
		int cnt=0;
		for (int i=0;i<n;++i){
			if (map[i][j]=='.'){
				cnt++;
			}
			else{
				ans+=max(cnt-k+1,0);
				cnt=0;
			}
		}
		ans+=max(cnt-k+1,0);
	}
	if (k==1){
		ans/=2;
	} 
	printf("%d\n",ans);
	return 0;
}