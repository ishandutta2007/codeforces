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

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if (x>y) puts("-1");
		else if ((y-x)%(a+b)) puts("-1");
		else printf("%d\n",(y-x)/(a+b));
	} 
}