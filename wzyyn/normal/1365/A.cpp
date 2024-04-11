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
int n,m,v1[55],v2[55];
void solve(){
	scanf("%d%d",&n,&m);
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v2));
	int s1=0,s2=0;
	For(i,1,n) For(j,1,m){
		int x;
		scanf("%d",&x);
		if (x){
			if (!v1[i]) ++s1;
			if (!v2[j]) ++s2;
			v1[i]=v2[j]=1;
		}
	}
	puts(min(n-s1,m-s2)&1?"Ashish":"Vivek");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}