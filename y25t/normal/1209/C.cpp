#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define N 200005

int T;

int n,a[N];
char s[N];

int ans[N];

inline void solve(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(int i=0;i<=9;i++){
		for(int j=1;j<=n;j++)
			ans[j]=2;
		std::stack<int> q;
		for(int j=1;j<=n;j++)
			if(a[j]<=i){
				ans[j]=1;
				while(!q.empty()&&a[q.top()]>a[j]){
					ans[q.top()]=2;
					q.pop();
				}
				q.push(j);
			}
			else
				ans[j]=2;
		bool flg=1;
		int tmp=0;
		for(int j=1;j<=n;j++)
			if(ans[j]==2){
				if(a[j]<a[tmp]||a[j]<i){
					flg=0;
					break;
				}
				tmp=j;
			}
		if(!flg)
			continue;
		for(int j=1;j<=n;j++)
			printf("%d",ans[j]);
		printf("\n");
		return;
	}
	printf("-\n");
}

int main(){
	scanf("%d",&T);
	while(T--)
		solve();
}