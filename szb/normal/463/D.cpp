#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<memory.h>
#define ll int 
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(ll x){
	if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}
void writeln(ll x){
	write(x);
	printf("\n");
}
ll b[1010][1010],f[1010],a[1010][1010],n,k;
bool pd(ll x,ll y){
	for (ll i=1;i<=k;i++)
		if (a[x][i]>a[y][i])	return false;
	return true;
}
int main(){
	n=read();	k=read();
	for (ll i=1;i<=k;i++){
		for (ll j=1;j<=n;j++){
			b[i][j]=read();
			a[b[i][j]][i]=j;
		}
	}
	for (ll i=1;i<=n;i++)	f[i]=1;
	for (ll i=2;i<=n;i++){
		for (ll j=1;j<i;j++)
			if (pd(b[1][j],b[1][i]))	f[i]=max(f[i],f[j]+1);
	}
	ll ans=0;
	for (ll i=1;i<=n;i++)	ans=max(ans,f[i]);
	writeln(ans);
}