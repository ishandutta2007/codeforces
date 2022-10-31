#include <bits/stdc++.h>
using namespace std;

int n,c;
int a[26];

int gcd(int a, int b) { return a==0 ? b : gcd(b%a,a); }

int main() {
	scanf("%d",&c);
	int odd = 0;
	for (int i=0;i<c;i++) {
		scanf("%d",&a[i]);
		n+=a[i];
		if (a[i]%2) {
			if (odd) odd = -1;
			else odd = i+1;
		}
	}
	if (odd==-1) {
		printf("0\n");
		for (int i=0;i<c;i++) {
			for (int j=0;j<a[i];j++) printf("%c",'a'+i);
		}
		printf("\n");
	} else {
		int num = 0;
		for (int i=0;i<c;i++) num = gcd(num,a[i]);
		printf("%d\n",num);
		if (!odd) num/=2;
		for (int r=0;r<num;r++) {
			for (int i=0;i<c;i++) {
				if (a[i]%2==1) continue;
				for (int j=0;j<a[i]/num/2;j++) printf("%c",'a'+i);
			}
			if (odd) {
				for (int i=0;i<a[odd-1]/num;i++) printf("%c",'a'+odd-1);
			}
			for (int i=c-1;i>=0;i--) {
				if (a[i]%2==1) continue;
				for (int j=0;j<a[i]/num/2;j++) printf("%c",'a'+i);
			}
		}
		printf("\n");
	}

	return 0;
}