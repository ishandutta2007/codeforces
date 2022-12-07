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
const int B=505;
const int N=200005;
int f[205][N];
int g[205][N];
int a[N],ar[N],nd,n,x;
map<int,int> mp;
int getid(int x){
	if (mp[x]) return mp[x];
	ar[mp[x]=++nd]=x;
	return nd;
}
int main(){
	scanf("%d",&n);
	int cnt=(n-1)/B+1;
	For(i,1,n) scanf("%d",&x),a[i]=getid(x);
	For(i,1,cnt){
		int L=(i-1)*B+1,R=min(i*B,n);
		memcpy(f[i],f[i-1],sizeof(f[i]));
		memcpy(g[i],g[i-1],sizeof(g[i]));
		For(j,L,R) g[i][++f[i][a[j]]]++;
	}
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y); 
	 	if (tp==1){
	 		int be=(y-1)/B+1;
	 		For(i,be,cnt) g[i][f[i][a[y]]--]--;
	 		a[y]=getid(x);
	 		For(i,be,cnt) g[i][++f[i][a[y]]]++;
	 	}
	 	else if (x==1) printf("%d\n",ar[a[y]]);
	 	else{
	 		x&=1;
	 		int be=(y-1)/B+1,R=min(be*B,n);
	 		Rep(i,R,y+1) g[be][f[be][a[i]]--]--;
	 		printf("%d\n",x&1?g[be][f[be][a[y]]]:f[be][a[y]]);
	 		For(i,y+1,R) g[be][++f[be][a[i]]]++;
	 	}
	}
}