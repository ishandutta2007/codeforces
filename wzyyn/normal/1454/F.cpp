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
int n,a[N],id[N],t[N];
bool cmp(int x,int y){
	return a[x]>a[y];
}
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
bool check(int l,int r){
	if (l>=1&&r<=n) 
	if (ask(l-1)>=1)
	if (ask(n)-ask(r)>=1)
	if (ask(r)-ask(l-1)==r-l+1){
		printf("YES\n%d %d %d\n",l-1,r-l+1,n-r);
		return 1;
	}
	return 0;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) id[i]=i,t[i]=0;
	sort(id+1,id+n+1,cmp);
	int l=n+1,r=0,p=1,f=0;
	For(i,1,n){
		for (;a[id[p]]>a[id[i]];++p){
			l=min(l,id[p]);
			r=max(r,id[p]);
			f=(ask(r)-ask(l-1)==r-l+1);
		}
		change(id[i],1);
		if (i>=3&&p==1){
			sort(id+1,id+4);
			printf("YES\n%d %d %d\n",id[2]-1,1,n-id[2]);
			return;
		}
		if ((i==n||a[id[i]]!=a[id[i+1]])&&p!=1){
			if (!f){
				if (check(l,r)) return;
			} 
			else{
				if (check(l-1,r)) return;
				if (check(l,r+1)) return;
			}
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}