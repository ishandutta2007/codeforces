#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int a[100],b[100];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d%d",a+i,b+i);
	}

	int mx=0;
	for(int i=0;i<n;i++) {
		if(a[i]>mx) break;
		mx=max(mx,b[i]);
	}
	puts(mx==m ? "YES" : "NO");
	return 0;
}