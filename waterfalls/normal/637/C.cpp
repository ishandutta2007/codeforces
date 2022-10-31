#include <bits/stdc++.h>
using namespace std;

int n;
char buff[10];
string num[1013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		num[i] = string(buff);
	}
	int ans = 6;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			int diff = 0;
			for (int k=0;k<6;k++) {
				if (num[i][k]!=num[j][k]) diff+=1;
			}
			ans = min(ans,(diff-1)/2);
		}
	}
	printf("%d\n",ans);

	return 0;
}