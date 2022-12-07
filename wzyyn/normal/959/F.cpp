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
const int mo=1000000007;
const int N=200005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,Q,x,y;
int a[N],b[25],ans[N];
vector<pii> vec[N];
void insert(int v){
	Rep(i,20,0){
		if ((v&(1<<i))&&!b[i]) b[i]=v;
		if ((v^b[i])<v) v^=b[i];
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,Q) scanf("%d%d",&x,&y),vec[x].PB(pii(y,i));
	For(i,1,n){
		insert(a[i]);
		for (auto j:vec[i]){
			int v=j.fi,S=i;
			Rep(p,20,0){
				if (b[p]) --S;
				if ((v^b[p])<v) v^=b[p];
			}
			if (!v)
				ans[j.se]=power(2,S);
		}
	}
	For(i,1,Q) printf("%d\n",ans[i]);
}