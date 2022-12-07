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
int n,a[1005],pos,ice,l,r,top;
char ans[1000005];
void solve(int l,int r){
	if (l>r) return;
	int mn=a[l];
	For(i,l,r) mn=min(mn,a[i]);
	For(i,l,r) a[i]-=mn;
	int la=l;
	For(i,l,r+1) if (!a[i]||i==r+1)
		solve(la,i-1),la=i+1;
	For(i,1,mn){
		for (;ice<r;){
			if (pos==ice) ans[++top]='A',++ice;
			else ans[++top]='R',++pos;
		}
		for (;pos+1>=l;--pos) ans[++top]='L';
		ans[++top]='A'; ice=pos;
	}
}
void work(int l,int r){
	if (l>r) return;
	int L=l-1;
	for (;a[L];--L);
	if (2*(l-L)>=r-l+1)
		For(i,l,r) a[i]=1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	for (l=1;!a[l];++l);
	for (r=n;!a[r];--r);
	int la=l;
	For(i,l,r+1) if (a[i]||i==r+1)
		work(la,i-1),la=i+1;
	pos=-1; ice=-1; solve(l,r);
	printf("%s",ans+1);
}
/*
7
2 0 0 0 0 0 2
7
2 1 1 1 1 1 2
*/