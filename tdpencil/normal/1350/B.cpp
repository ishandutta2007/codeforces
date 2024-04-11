#include<bits/stdc++.h>
using namespace std;
 
#define ran 101101
 
int n;
int a[ran];
int f[ran];
 
void upd(int &a, int b) {
	if (a<b) a=b;
}
 
int main() {
	int T;
	for(scanf("%d", &T); T--;) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) scanf("%d", &a[i]);
		
		int ans = 1;
		f[1] = 1;
		for(int i=2;i<=n;i++) {
			f[i] = 1;
			if (a[i]>a[1]) upd(f[i], f[1]+1);
			for(int j=2;j*j<=i;j++)
				if (i%j==0) {
					if (a[i]>a[j]) upd(f[i], f[j]+1);
					if (a[i]>a[i/j]) upd(f[i], f[i/j]+1);
				}
			
			upd(ans, f[i]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}