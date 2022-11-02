#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int ne[N],tot,fi[N],zz[N],x,y,n,m,a[N],b[N],c[N];
char s[N];
inline void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
} 
signed main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;i++){
		int flag=1;
		for (int j=1;j<i;j++)
			if (a[i]%a[j]==0)flag=0;
		ans+=flag;	
	} 
	printf("%d\n",ans);
}