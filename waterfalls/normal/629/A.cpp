#include <bits/stdc++.h>
using namespace std;

int n;
char grid[113][113];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
	int ans = 0;
	for (int i=0;i<n;i++) {
        int cnt = 0;
        for (int j=0;j<n;j++) cnt+=grid[i][j]=='C';
        ans+=cnt*(cnt-1)/2;
        cnt = 0;
        for (int j=0;j<n;j++) cnt+=grid[j][i]=='C';
        ans+=cnt*(cnt-1)/2;
	}
	printf("%d\n",ans);

	return 0;
}