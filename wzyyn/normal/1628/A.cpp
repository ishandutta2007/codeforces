#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],s[N],b[N];
int vis[N],q[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	reverse(a+1,a+n+1);
	for (int i=0;i<=n;i++)
		s[i]=0;
	int p=0;
	for (int i=1;i<=n;i++){
		++s[a[i]];
		for (;s[p];++p);
		b[i]=p;
	}
	*q=0;
	for (int i=n;i;){
		int v=b[i],rem=v;
		for (int j=0;j<v;j++) vis[j]=0;
		q[++*q]=v;
		for (;;){
			if (a[i]<v&&!vis[a[i]]) --rem;
			vis[a[i]]=1;
			--i;
			if (!rem) break;
		}
	}
	printf("%d\n",*q);
	for (int i=1;i<=*q;i++)
		printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}