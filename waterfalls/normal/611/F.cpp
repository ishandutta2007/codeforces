#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int mult(int a, int b) { return ((long long) a*b)%MOD; }

int n,h,w;
char s[500013];
int dX[200], dY[200];
int diffx, diffy;
int maxx, minx;
int maxy, miny;
int hasx_[1000013], hasy_[1000013];
int& hasx(int i) { return hasx_[i+500000]; }
int& hasy(int i) { return hasy_[i+500000]; }

void calc() {
	int x = 0, y = 0;
	for (int i=0;i<n;i++) {
		x+=dX[s[i]];
		y+=dY[s[i]];
		maxx = max(maxx,x);
		minx = min(minx,x);
		maxy = max(maxy,y);
		miny = min(miny,y);
		if (!hasx(x)) hasx(x) = i+1;
		if (!hasy(y)) hasy(y) = i+1;
	}
	diffx = x; diffy = y;
}

int main() {
	dX['U'] = -1; dX['D'] = 1;
	dY['L'] = -1; dY['R'] = 1;
	scanf("%d%d%d %s",&n,&h,&w,&s);
	calc();
	if (maxx-minx+1<=h && maxy-miny+1<=w && diffx==0 && diffy==0) return printf("-1\n"), 0;
	int bot = -1, top = h;
	int lef = -1, rig = w;
	int x = 0, y = 0;
	int step = 0;
	int ans = 0;
	while (top>bot+1 && rig>lef+1) {
		int tryt = 1e9;
		if (x+top-1+maxx>=h) tryt = hasx(h-(top+x-1));
		int tryb = 1e9;
		if (x+bot+1+minx<=-1) tryb = hasx(-1-(bot+x+1));
		int tryr = 1e9;
		if (y+rig-1+maxy>=w) tryr = hasy(w-(rig+y-1));
		int tryl = 1e9;
		if (y+lef+1+miny<=-1) tryl = hasy(-1-(lef+y+1));
		if (min(min(tryt,tryb),min(tryr,tryl))<1e7) {
			if (tryt<min(tryb,min(tryr,tryl))) {
				int cur = mult(rig-lef-1,mult(step,n)+tryt);
				ans = add(ans,cur);
				top-=1;
			} else if (tryb<min(tryt,min(tryr,tryl))) {
				int cur = mult(rig-lef-1,mult(step,n)+tryb);
				ans = add(ans,cur);
				bot+=1;
			} else if (tryr<min(tryt,min(tryb,tryl))) {
				int cur = mult(top-bot-1,mult(step,n)+tryr);
				ans = add(ans,cur);
				rig-=1;
			} else if (tryl<min(tryt,min(tryb,tryr))) {
				int cur = mult(top-bot-1,mult(step,n)+tryl);
				ans = add(ans,cur);
				lef+=1;
			}
		} else {
			x+=diffx; y+=diffy;
			step+=1;
		}
	}
	printf("%d\n",ans);

	return 0;
}