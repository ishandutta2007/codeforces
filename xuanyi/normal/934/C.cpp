#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;

const int MAXN=2005,MAXL=15;
int n,ans,A[MAXN];
char ch,s[MAXL];

struct node {
	int x, y, mx0, mx1, tag ;
} tr[MAXN << 2] ;

void psd(int u){
	if (tr[u].tag){
		tr[u].tag = 0 ;
		tr[u << 1].tag ^= 1, swap(tr[u << 1].x, tr[u << 1].y), swap(tr[u << 1].mx0, tr[u << 1].mx1) ;
		tr[u << 1 | 1].tag ^= 1, swap(tr[u << 1 | 1].x, tr[u << 1 | 1].y), swap(tr[u << 1 | 1].mx0, tr[u << 1 | 1].mx1) ;
	}
}

void upd(int u) {
	psd(u);
	tr[u].x = tr[u << 1].x + tr[u << 1 | 1].x ;
	tr[u].y = tr[u << 1].y + tr[u << 1 | 1].y ;
	tr[u].mx0 = max(tr[u << 1].mx0 + tr[u << 1 | 1].y, tr[u << 1].x + tr[u << 1 | 1].mx0) ;
	tr[u].mx1 = max(tr[u << 1].mx1 + tr[u << 1 | 1].x, tr[u << 1].y + tr[u << 1 | 1].mx1) ;
}

void bud(int u, int l, int r) {
	if (l == r) {
		if (A[l]) tr[u].x = 1 ; else tr[u].y = 1 ;
		tr[u].mx0 = tr[u].mx1 = 1 ; return ;
	}
	int mid = (l + r) / 2 ;
	bud(u << 1, l, mid) ;
	bud(u << 1 | 1, mid + 1, r) ;
	upd(u) ;
}

void mdf(int u, int l, int r, int lx, int rx) {
	if (l == lx && r == rx) {
		tr[u].tag ^= 1 ;
		swap(tr[u].x, tr[u].y) ;
		swap(tr[u].mx0, tr[u].mx1) ;
		return ;
	}
	psd(u) ;
	int mid = (l + r) / 2 ;
	if (rx <= mid) mdf(u << 1, l, mid, lx, rx) ; else
	if (mid < lx) mdf(u << 1 | 1, mid + 1, r, lx, rx) ; else
		mdf(u << 1, l, mid, lx, mid), mdf(u << 1 | 1, mid + 1, r, mid + 1, rx) ;
	upd(u) ;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",A+i),A[i]--;
	bud(1,1,n);
	ans=tr[1].mx1;
	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			mdf(1,1,n,r,r);
			ans=max(ans,tr[1].mx1);
		}
		mdf(1,1,n,l,n);
	}
	printf("%d\n",ans);
	return 0;
}