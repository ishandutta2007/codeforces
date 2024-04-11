#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=300005;
int n,m,q[N];
int a[N],s[N],b[N],vis[N];
bool check(int v){
	for (int i=1;i<=n;i++)
		b[i]=(a[i]+n-1+v)%n+1,vis[i]=0;
	int s=0;
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			int l=0,j=i;
			for (;!vis[j];){
				vis[j]=1;
				j=b[j]; ++l;
			}
			s+=l-1;
		}
	return s<=m;
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=0;
	for (int i=1;i<=n;i++)
		++s[(i-a[i]+n)%n];
	*q=0;
	for (int i=0;i<n;i++)
		if (s[i]>=n/5&&check(i))
			q[++*q]=i;
	printf("%d ",*q);
	for (int i=1;i<=*q;i++)
		printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}