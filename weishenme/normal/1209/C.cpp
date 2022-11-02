#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int ne[N],tot,fi[N],zz[N],x,T,y,n,m,a[N],b[N],c[N];
char s[N];
inline void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
} 
int cmp(int x,int y){
	return a[x]<a[y]||(a[x]==a[y]&&x<y);
}
int cmp2(int x,int y){
	return c[x]<c[y]||(c[x]==c[y]&&x<y);
}
void doit(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)a[i]=s[i]-48,b[i]=i;
	sort(b+1,b+n+1,cmp);
	int last=1,Min=1e9;
	for (int i=1;i<=n;i++){
		if (c[b[i]]){
			if (Min==a[b[i]])continue;
			break;
		}
		if (Min<a[b[i]])break;
		c[b[i]]=1;
		for (;last!=b[i];last++)
			if (!c[last])c[last]=2,Min=min(Min,a[last]);
	}
	for (;last<=n;last++)
		if (!c[last])c[last]=2;
	sort(b+1,b+n+1,cmp2);
	int flag=0;
	for (int i=2;i<=n;i++)
		if (a[b[i]]<a[b[i-1]]){
			puts("-");
			flag=1;
			break;
		}
	if (!flag){
		for (int i=1;i<=n;i++)putchar(c[i]+48);
		puts("");
	}
}
signed main(){
	scanf("%d",&T);
	while (T--){
		doit();
		for (int i=1;i<=n;i++)c[i]=0;
	}
}