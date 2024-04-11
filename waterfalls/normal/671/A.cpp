#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

double dist(int a, int b, int c, int d) {
	return sqrt(1LL*(c-a)*(c-a)+1LL*(d-b)*(d-b));
}

int ax,ay,bx,by,tx,ty,n;
vector<pair<double,int> > a,b;

int main() {
	scanf("%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty,&n);
	double tot = 0;
	for (int i=0;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		tot+=2*dist(x,y,tx,ty);
		a.push_back(MP(dist(ax,ay,x,y)+dist(x,y,tx,ty)-2*dist(x,y,tx,ty),i));
		b.push_back(MP(dist(bx,by,x,y)+dist(x,y,tx,ty)-2*dist(x,y,tx,ty),i));
	}
	double ans = tot+min(dist(ax,ay,tx,ty),dist(bx,by,tx,ty));
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for (int i=0;i<2;i++) {
		for (int r=0;r<min(2,n);r++) {
			double cur = a[r].A;
			int on = (a[r].B==b[0].B);
			if (n>on && b[on].A<0) cur+=b[on].A;
			ans = min(ans,tot+cur);
		}
		swap(a,b);
	}
	printf("%1.9f\n",ans);

	return 0;
}