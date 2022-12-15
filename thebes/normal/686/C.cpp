#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, A, B, ans, fl, cnt[10];
int main(){
	scanf("%d%d",&n,&m);
	A=B=1;
	for(int wtf=7;wtf<n;wtf*=7)A++;
	for(int wtf=7;wtf<m;wtf*=7)B++;
	if(A+B>7) printf("0\n");
	else if(n==1&&m==1) printf("0\n");
	else{
		for(i=0;i<n;i++){
			for(int j=0;j<m;j++){
				vector<int> used(7, 0);
				for (int a = i, k = 0; k < A; a /= 7, ++k)
					used[a % 7] += 1;
				for (int b = j, k = 0; k < B; b /= 7, ++k)
					used[b % 7] += 1;
				fl = 0;
				for(auto v : used)
					if(v>1) fl=1;
				if(!fl) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}