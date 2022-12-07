#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=205;
int n,k;
int vis[N],mat[N],q[N];
void solve(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=2*n;i++) vis[i]=0; 
	for (int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		vis[x]=vis[y]=1;
		mat[x]=y; mat[y]=x;
	}
	*q=0;
	for (int i=1;i<=2*n;i++)
		if (!vis[i]) q[++*q]=i;
	for (int i=1;i<=n-k;i++){
		mat[q[i]]=q[i+n-k];
		mat[q[i+n-k]]=q[i];
	}
	*q=0;
	for (int i=1;i<=2*n;i++)
		if (i>mat[i]) q[++*q]=i;
	int ans=0;
	for (int i=1;i<=*q;i++)
		for (int j=i+1;j<=*q;j++)
			if (mat[q[j]]<q[i]&&mat[q[j]]>mat[q[i]])
				++ans;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}