#include<bits/stdc++.h>

using namespace std;

int n,ans[10005],q[10005];
int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		ans[i]=-1;
	for (int i=1;i<=n;i++)
		if (ans[i]==-1){
			*q=0;
			int x=ask(i);
			int y=q[++*q]=ask(i);
			for (;y!=x;) q[++*q]=y=ask(i);
			for (int j=1;j<=*q;j++) ans[q[j]]=(j==*q?q[1]:q[j+1]);
		}
	putchar('!');
	for (int i=1;i<=n;i++)
		printf(" %d",ans[i]);
	puts("");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}