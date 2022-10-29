#include <cstdio>
#include <cstring>
#include <algorithm>
int f[105][10][905];
int m,s;
int dfs(int len,int k,int sum) {
	if (len == 1) {
		if (k == sum) f[len][k][sum] = 1;
		else f[len][k][sum] = 0;
	}
	if (f[len][k][sum] != -1) return f[len][k][sum];
	int bo = 0;
	for (int i = 0; i <= 9; ++i) 
		if (sum - i - k >= 0) bo |= dfs(len - 1,i,sum - k);
	f[len][k][sum] = bo;
	return f[len][k][sum];
}
void min(int len,int k,int sum) {
	printf("%d",k);
	if (len == 1) return;
	for (int i = 0; i <= 9; ++i)
		if (sum - i - k >= 0 && f[len - 1][i][sum - k] == 1) {
			min(len - 1,i,sum - k);
			break;
		}
}
void max(int len,int k,int sum) {
	printf("%d",k);
	if (len == 1) return;
	for (int i = 9; i >= 0; --i)
		if (sum - i - k >= 0 && f[len - 1][i][sum - k] == 1) {
			max(len - 1,i,sum - k);
			break;
		}
}
int main() {
	scanf("%d%d",&m,&s);
	memset(f,255,sizeof(f));
	if (m == 1) {
		if (s >= 0 && s <= 9) printf("%d %d\n",s,s);
		else printf("-1 -1\n");
	}
	else {
		int bo = 0;
		for (int i = 1; i <= 9; ++i) 
			if (s >= i) 
				bo |= dfs(m,i,s);
		if (bo == 0) printf("-1 -1\n");
		else {
			for (int i = 1; i <= 9; ++i) 
				if (s >= i && f[m][i][s] == 1) {
					min(m,i,s); break;
				}
			printf(" ");
			for (int i = 9; i >= 1; --i) 
				if (s >= i && f[m][i][s] == 1) {
					max(m,i,s); break;
				}
			printf("\n");
		}
	}
}