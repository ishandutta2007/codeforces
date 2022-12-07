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
const int N=200005;
set<pii> S;
vector<pii> vec[N];
int n,L[N],R[N],ans[N];
int pos[N],t[N*4];
void change(int k,int l,int r,int p,int v){
	t[k]=v;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
}
int ask(int k,int l,int r,int x,int y){
	if (x>y) return 0;
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (x<=mid){
		int tmp=ask(k*2,l,mid,x,y);
		if (tmp) return tmp;
	}
	if (y<=mid) return 0;
	return ask(k*2+1,mid+1,r,x,y);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&L[i],&R[i]);
	For(i,1,n) vec[L[i]].PB(pii(R[i],i));
	For(i,1,n){
		for (auto j:vec[i]) S.insert(j);
		ans[S.begin()->se]=i;
		pos[i]=S.begin()->se; 
		S.erase(S.begin());
	}
	//For(i,1,n) cout<<ans[i]<<endl;
	For(i,1,n){
		for (auto j:vec[i]) change(1,1,n,ans[j.se],j.se);
		if (ask(1,1,n,i+1,R[pos[i]])){
			int j=ask(1,1,n,i+1,R[pos[i]]);
			//cout<<i<<' '<<j<<' '<<pos[i]<<' '<<R[pos[i]]<<endl;
			puts("NO");
			For(k,1,n) printf("%d ",ans[k]);
			puts("");
			swap(ans[pos[i]],ans[j]);
			For(k,1,n) printf("%d ",ans[k]);
			exit(0);
		}
	}
	puts("YES");
	For(k,1,n) printf("%d ",ans[k]);
	puts("");
	
}