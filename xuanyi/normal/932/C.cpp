#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1000005;
int N,A,B,ans[MAXN],now,lst=1;
bool f[MAXN],fa[MAXN];
void solve(){
	for (int i=N;i;){
		if (fa[i]){
			i-=B; ans[lst]=lst+B-1;
			for (int i=lst+1;i<lst+B;i++) ans[i]=i-1;
			lst=lst+B;
		}else{
			i-=A; ans[lst]=lst+A-1;
			for (int i=lst+1;i<lst+A;i++) ans[i]=i-1;
			lst=lst+A;
		}
	}
	for (int i=1;i<=N;i++){
		printf("%d",ans[i]);
		if (i==N) putchar('\n'); else
			putchar(' ');
	}
}
int main(){
	scanf("%d%d%d",&N,&A,&B);
	f[0]=1;
	for (int i=1;i<=N;i++){
		if (i>=A&&f[i-A]) f[i]=1,fa[i]=0; else
		if (i>=B&&f[i-B]) f[i]=1,fa[i]=1;
	}
	if (!f[N]) puts("-1"); else solve();
	return 0;
}