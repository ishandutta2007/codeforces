#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,ans;
int a[N],ind[N],vis[N],q[N];
void solve(){
	scanf("%d",&n);
	int ans=n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) ind[i]=vis[i]=0;
	for (int i=1;i<=n;i++) ++ind[a[i]];
	for (int i=1;i<=n;i++) if (!vis[i]){
		*q=0;
		for (int j=i;j&&!vis[j];j=a[j])
			vis[j]=1,q[++*q]=j;
		int t=1;
		for (;t<=*q&&a[q[*q]]!=q[t];++t);
		if (t<=*q){
			int pre=q[*q];
			for (int j=t;j<=*q;j++){
				if (ind[q[j]]!=1)
					a[pre]=0,--ans;
				pre=q[j];
			}
		}
	}
	for (int i=1;i<=n;i++) ind[i]=0;
	for (int i=1;i<=n;i++)
		if (a[i]&&ind[a[i]])
			a[i]=0,ans--;
		else ind[a[i]]=1;
	int fi=-1,la=-1;
	for (int i=1;i<=n;i++)
		if (!ind[i]){
			if (la!=-1) a[la]=i;
			if (fi==-1) fi=i;
			for (la=i;a[la];la=a[la]);
		}
	a[la]=fi;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
}

int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}