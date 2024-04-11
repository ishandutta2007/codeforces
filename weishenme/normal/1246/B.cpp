#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000005;
int ne[N],tot,fi[N],zz[N],n,m,a[N],b[N],c[N],x,y;
char s[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
int check(int x,int y){
	int ans=1;
	while (y--){
		if (10000000000/ans<x)return 0;
		ans*=x;
	}
	return 1;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if (m==2){
		for (int i=1;i<=n;i++)
			for (int j=2;j*j<=a[i];j++)
				while (a[i]%(j*j)==0)a[i]/=j*j;
		int ans=0;		
		for (int i=1;i<=n;i++)ans+=b[a[i]],b[a[i]]++;
		printf("%lld\n",ans);
		return 0;
	} 
	int ans=0;
	for (int k=1;check(k,m);k++){
		int kk=1;for (int i=1;i<=m;i++)kk*=k; 
		for (int i=1;i<=n;i++){
			if (kk%a[i]==0&&kk/a[i]<=100000)ans+=b[kk/a[i]];
			b[a[i]]++;
		}
		for (int i=1;i<=n;i++)b[a[i]]--;
	}
	printf("%lld\n",ans);
}