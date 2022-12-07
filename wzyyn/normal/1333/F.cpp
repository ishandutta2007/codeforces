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
const int N=500005;
int mn[N],v[N],n;
void init(){
	mn[1]=1;
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j]) mn[i*j]=i;
	For(i,1,N-1) v[i]=i/mn[i];
}
int main(){
	scanf("%d",&n);
	init();
	sort(v+1,v+n+1);
	For(i,2,n) printf("%d ",v[i]); puts("");
}