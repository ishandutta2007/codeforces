#include <bits/stdc++.h>

const int maxn = 101010;
const double eps = 1e-8;

int n,d;
int a[maxn];
long double lga[maxn],f[20],c[20];

std::pair<int,int> tmp[20],cur[maxn][10];
int ma[20];
std::vector<int> ans;

int main () {
	scanf("%d%d",&n,&d);
	for (int i = 1; i <= n; i++) {
		scanf("%d",a + i);
		lga[i] = std::log(1. * a[i]);
	}

	for (int i = 0; i <= 9; i++) f[i] = -1;

	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (int j = 0; j <= 9; j++) c[j] = f[j];
		for (int j = 0; j <= 9; j++) {
			int s = a[i] % 10;
			if (j == s) {
				if (lga[i] > c[j]) {
					tmp[++tot] = {-1,j};
					c[j] = std::max(lga[i],c[j]);
				}
			}
			int h = j*a[i]%10;
			long double  p = f[j];
			if(f[j] < 0)continue;
			p += lga[i];
			if(p - c[h] >= 0){
				tmp[++tot] = {j,h};
				c[h] = std::max(c[h],p);
			}
		}

		for (int j = 1; j <= tot; j++) {
			int lst = tmp[j].first;
			int dig = tmp[j].second;
			cur[i][dig] = {ma[lst],lst};
		}

		for (int j = 1; j <= tot; j++) ma[tmp[j].second] = i;
		for (int j = 0; j <= 9; j++) f[j] = std::max(c[j],f[j]);
	}

	if (f[d] < 0) {
		puts("-1");
		return 0;
	}
	int nowx = ma[d];
	int nowd = d;

	while (nowx) {
		ans.push_back(nowx);
		int lstx = cur[nowx][nowd].first;
		int lstd = cur[nowx][nowd].second;
		nowx = lstx;
		nowd = lstd;
	}

	printf("%d\n",ans.size());
	for (auto &x : ans) 
		printf("%d ",a[x]);

	return 0;
}