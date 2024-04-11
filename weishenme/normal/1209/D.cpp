#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int ne[N],tot,fi[N],zz[N],x,y,ans,n,m,a[N],b[N],c[N];
char s[N];
inline void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
} 
int find(int x){
	if (x==a[x])return x;
	return a[x]=find(a[x]);
}
signed main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)a[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[find(x)]=find(y);
	}
	for (int i=1;i<=n;i++)b[find(i)]++;
	for (int i=1;i<=n;i++)
		if (b[i])ans+=b[i]-1;
	printf("%d\n",m-ans);	
}