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
	scanf("%s",s+1); 
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		int now=s[i]-48;
		for (int j=0;j<=100000;j++){
			if (j>=y&&(j-y)%x==0)now=now^1;
			a[j]+=now;
		}
	}
	for (int i=0;i<=100000;i++)m=max(m,a[i]);
	printf("%d\n",m);
}