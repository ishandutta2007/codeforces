%:pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

const int mod = 2172297099;
const int fst = 1331;
const int N = 5001;

char s[N];
short ans[N][N];
int ha[N][N] , hw[N][N] , cal[N];
int calc(int l,int r) {
	int p = 0;
	p = ha[l][r - 1] * fst + s[r];
	p = p % mod;
	return p;
}


int CALC(int l,int r) {
	int p= hw[l + 1][r] * fst + s[l];
	p = p % mod;
	return p;
}

int main() {
	scanf("%s",s + 1);
	int l = strlen(s + 1);
	int n = l;
	for(int len = 1;len <= l; len ++) {
		for(int j = 1;j <= n - len +1; j ++) {
			ha[j][len + j -1] = calc(j ,len + j -1);
			hw[j][len + j -1] = CALC(j ,len + j -1);
			if(len % 2==1) {
				if(hw[j][j + len - 1] == ha[j][j + len -1]) {
					if(ha[j][j + len /2 - 1] == ha[j + len /2+ 1][j + len -1]) {
						ans[j][len + j -1] = ans[j][j + len / 2 - 1] + 1;
					}
					else
					ans[j][len + j -1] =1;
				}
			}
			else  {
				if(hw[j][j + len  - 1] == ha[j][j + len - 1]) {
					if(ha[j][j + len / 2 - 1] == ha[j + len / 2][j + len - 1]) {
						ans[j][len + j -1] = ans[j][j + len / 2 - 1] + 1;
					}
					else ans[j][len + j - 1] = 1;
				}
			}
		}
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			cal[ans[i][j]] ++;
		}
	}
	for(int i = n;i >=1;i--) {
		cal[i - 1] +=cal[i];
	}
	for(int i = 1;i <=n;i ++) printf("%d ",cal[i]);
}