#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=15005;
int n,a[N];
int f[N][2],g[N][2];
int of[N][2],og[N][2];
struct Tarr{
	int t[N];
	void init(int n){
		for (int i=0;i<=n;i++) t[i]=n+1;
	}
	void change(int x,int v){
		for (;x<=n;x+=x&(-x)) t[x]=min(t[x],v);
	}
	int ask(int x){
		int s=n+1;
		for (;x;x-=x&(-x)) s=min(s,t[x]);
		return s;
	}
}T1,T2;
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1){
		puts("1");
		return;
	}
	
	for (int i=0;i<=n+1;i++){
		f[i][0]=f[i][1]=n+1;
		g[i][0]=g[i][1]=0; 
	}
	f[n][0]=g[n][0]=a[n];
	for (int i=1;i<=n-1;i++)
		f[i][1]=g[i][1]=a[i];
	
	int ans=1,R=1;
	for (;;){
		for (int c=0;c<=1;c++){
			for (int i=0;i<=n+1;i++){
				of[i][c]=f[i][c];
				og[i][c]=g[i][c];
			}
			T1.init(n); T2.init(n);
			for (int i=n;i>=1;i--){
				f[i][c]=T1.ask((n+1)-a[i]);
				g[i][c]=(n+1)-T2.ask(a[i]);
				if (of[i][c]!=n+1) T1.change((n+1)-a[i],of[i][c]);
				if (og[i][c]!=0) T2.change(a[i],(n+1)-og[i][c]);
			}
			T1.init(n); T2.init(n);
			for (int i=n;i>=1;i--){
				if (i+R+c<=n){
					if (og[i+R+c][c]!=0) T1.change((n+1)-og[i+R+c][c],a[i+R+c]);
					if (of[i+R+c][c]!=n+1) T2.change(of[i+R+c][c],(n+1)-a[i+R+c]);
				}
				f[i][c]=min(f[i][c],T1.ask((n+1)-a[i]));
				g[i][c]=max(g[i][c],(n+1)-T2.ask(a[i]));
			}
		}
		bool flag=0;
		for (int i=1;i<=n;i++)
			for (int c=0;c<=1;c++){
				if (f[i][c]!=n+1) flag=1;
				if (g[i][c]!=0) flag=1;
			}
		if (!flag){
			printf("%d\n",R);
			return;
		}
		++R; ++ans;		
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}