#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 501;

typedef long long LL;

int n , l , r , m ,a[N];
LL ans , res;
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) {
		scanf("%d",&a[i]);
	}
	ans = 0;
	for(int i = 1;i <= m;i ++) {
		scanf("%d%d" ,&l,&r);
		res = 0;
		for(int j = l;j <= r;j ++) res +=(long long)a[j];
		if(res >= 0) ans += res; 
	}
	cout<<ans<<endl;
}