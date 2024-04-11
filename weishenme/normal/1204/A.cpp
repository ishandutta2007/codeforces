#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=1000005;
char s[N];
int a[N],b[N],c[N],n,m,k,tot,ne[N],fi[N],zz[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
int read(){
	int x=0;char c=0;
	for (;c<'0'||c>'9';c=getchar());
	for (;c>='0'&&c<='9';c=getchar())x=x*10+c-48;
	return x;
}
int main(){
	scanf("%s",s);
	for (int i=1;s[i];i++)
		if (s[i]=='1')n=1;
	n|=!(strlen(s)&1);	
	printf("%d\n",(strlen(s)-1)/2+n);	
}