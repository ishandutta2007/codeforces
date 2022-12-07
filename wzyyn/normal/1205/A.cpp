#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,ans[200005];
int main(){
	scanf("%d",&n);
	if (n%2==0) return puts("NO"),0;
	puts("YES");
	int posi=1;
	For(i,1,2*n){
		ans[posi]=i;
		if (i&1){
			if (posi<=n) posi+=n;
			else posi-=n;
		}
		else posi++;
	}
	For(i,1,2*n) printf("%d ",ans[i]);
}