#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 200005;

struct NODE{
	int l , r;
	int len;
	friend bool operator < (NODE xxx , NODE yyy) {
		return xxx.len < yyy.len;
	}
}ele[N];

int n , m ,a[N] , ans ,p[N];

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m ;i ++) {
		scanf("%d%d",&ele[i].l ,&ele[i].r);
		ele[i].len = ele[i].r - ele[i].l + 1;
	}
	sort(ele + 1 , ele + m + 1);
	NODE index = ele[1];
	ans = ele[1].len;
	int mod = ele[1].len , k = 0;
	for(int i = index.l; i<= index.r;i ++) {
		p[i % mod] = k;k ++;
	}
	for(int i = 1;i <= n;i ++) {
		a[i] = p [i % mod];
	}
	printf("%d\n",ans);
	for(int i = 1;i <= n;i ++) printf("%d ",a[i]);
	puts("");
}