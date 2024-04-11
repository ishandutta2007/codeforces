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
int vl[N],vr[N],n;
void solve(){
	scanf("%d",&n);
	For(i,1,n) vl[i]=vr[i]=0;
	For(i,1,n){
		int mv=0,s,x;
		scanf("%d",&s);
		For(j,1,s){
			scanf("%d",&x);
			if (!vr[x]&&!mv) mv=x;
		}
		if (mv) vl[i]=vr[mv]=1;
	}
	int p1=0,p2=0;
	For(i,1,n){
		if (!vl[i]) p1=i;
		if (!vr[i]) p2=i;
	}
	if (p1)
		printf("IMPROVE\n%d %d\n",p1,p2);
	else puts("OPTIMAL");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}