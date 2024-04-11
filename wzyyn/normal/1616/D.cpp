#include<bits/stdc++.h>

using namespace std;

const int N=50005;
int n,x;
int a[N];
int f[2][2],g[2][2];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	if (n==1) return puts("1"),void(0);
	f[0][0]=0;
	f[0][1]=1;
	f[1][0]=1;
	f[1][1]=(a[1]+a[2]>=2*x?2:-(1<<30));
	for (int i=3;i<=n;i++){
		memset(g,233,sizeof(g));
		for (int f1=0;f1<=1;f1++)
			for (int f2=0;f2<=1;f2++){
				g[f2][0]=max(g[f2][0],f[f1][f2]);
				if (!f2||(a[i]+a[i-1]>=2*x))
					if (!f2||!f1||(a[i]+a[i-1]+a[i-2]>=3*x))
						g[f2][1]=max(g[f2][1],f[f1][f2]+1);
			}
		memcpy(f,g,sizeof(f));
	}
	int ans=0;
	for (int f1=0;f1<=1;f1++)
		for (int f2=0;f2<=1;f2++)
			ans=max(ans,f[f1][f2]);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}