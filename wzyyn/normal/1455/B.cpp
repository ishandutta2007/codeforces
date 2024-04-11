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
const int N=1500005;
int f[N];
void solve(){
	int x;
	scanf("%d",&x);
	printf("%d\n",f[x]);
}
int main(){
	int s=0;
	for (int i=1;s+i<N;++i){
		f[s+=i]=i;
		For(j,2,i+1) if (j<=s)
			if (!f[s-j]) f[s-j]=i;
	}
	int T;
	scanf("%d",&T);
	while (T--) solve();
}