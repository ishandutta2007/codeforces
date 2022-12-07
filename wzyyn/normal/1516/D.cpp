#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int n,Q;
int di[N],a[N];
int la[N],fa[N][20];
void init(){
	for (int i=2;i<N;i++)
		for (int j=1;j<=(N-1)/i;j++)
			if (!di[i*j]) di[i*j]=i;
}
int main(){
	init();
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<N;i++) la[i]=n+1;
	fa[n+1][0]=n+1;
	for (int i=n;i>=1;i--){
		fa[i][0]=fa[i+1][0];
		for (;a[i]!=1;){
			int v=di[a[i]];
			fa[i][0]=min(fa[i][0],la[v]);
			for (;a[i]%v==0;a[i]/=v);
			la[v]=i;
		}
	}
	for (int i=1;i<=16;i++)
		for (int j=1;j<=n+1;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int s=0;
		for (int i=16;i>=0;i--)
			if (fa[l][i]<=r){
				l=fa[l][i];
				s+=1<<i;
			}
		printf("%d\n",s+1);
	}
}