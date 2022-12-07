#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,vis[N];
void solver1(){
	if (n&1) return puts("NO"),void(0);
	puts("YES");
	Rep(i,n,1) if (!vis[i]){
		int j=1;
		for (;j*2<=i;j*=2);
		j=2*j-1-i;
		vis[i]=j; vis[j]=i;
	}
	For(i,1,n)
		printf("%d ",vis[i]);
	puts("");
}
void solver2(){
	if ((n&(-n))==n||n<=5) return puts("NO"),void(0);
	if (n==6) return printf("YES\n3 6 2 5 1 4\n"),void(0);
	puts("YES");
	vis[1]=7; vis[7]=4; vis[4]=5; vis[5]=1;
	vis[2]=3; vis[3]=6; vis[6]=2;
	for (int i=8;i<=n;i*=2)
		for (int j=i;j<i*2&&j<=n;j++)
			vis[j]=(j==i*2-1||j==n?i:j+1);
	For(i,1,n)
		printf("%d ",vis[i]);
	puts("");
}
int main(){
	scanf("%d",&n);
	solver1();
	solver2();
}