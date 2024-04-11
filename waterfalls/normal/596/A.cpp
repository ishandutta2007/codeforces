#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int minx = 1e5, miny = 1e5, maxx = -1e5,maxy = -1e5;
	for (int i=0;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		minx = min(minx,x);
		miny = min(miny,y);
		maxx = max(maxx,x);
		maxy = max(maxy,y);
	}
	if (minx==maxx || miny==maxy) printf("-1\n");
	else printf("%d\n",(maxx-minx)*(maxy-miny));

	return 0;
}