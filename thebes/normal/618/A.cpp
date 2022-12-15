#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int st[MN], top=-1, n, i;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		st[++top] = 1;
		while(top>=1&&st[top]==st[top-1])
			st[--top]++;
	}
	for(i=0;i<=top;i++)
		printf("%d ",st[i]);
	return 0;
}