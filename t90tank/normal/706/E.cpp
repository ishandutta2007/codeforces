#include <iostream> 
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std; 

using ll = long long; 

const int maxn = 1006; 

int n, m, q, t; 
int p[maxn*maxn][2]; 
int a[maxn*maxn]; 
int h[maxn][2];
vector<pair<int*,int*>> que; 

void getlink(int a, int b, int c, int d, int l, int w) {
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl; 
	int x = h[a][w]; 
	int y = h[c][w]; 
	for (int i = 1; i <= b; ++i) x = p[x][w]; 
	for (int i = 1; i <= d; ++i) y = p[y][w]; 
	
	while (l--) {
//		cout<<x<<"<->"<<y<<endl;
		que.push_back({&p[x][w], &p[y][w]}); 
		x = p[x][1-w]; 
		y = p[y][1-w]; 
	}
}

int main() {
	cin>>n>>m>>q; 
	t = 0; 
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			scanf( "%d", &a[i*(m+1)+j] ); 
	for (int i = 0; i <= n; ++i) 
		for (int j = 0; j <= m; ++j) {
			p[i*(m+1)+j][0] = i*(m+1)+j+1; 
			p[i*(m+1)+j][1] = (i+1)*(m+1)+j; 
		}
	for (int i = 1; i <= n; ++i) h[i][0] = i*(m+1)+0; 
	for (int i = 1; i <= m; ++i) h[i][1] = 0*(m+1)+i; 
	while (q--) {
//		for (int i = 1; i <= n; ++i) {
//			int x = p[h[i][0]][0]; 
//			for (int j = 1; j <= m; ++j, x=p[x][0]) 
//				printf( "%d ", a[x] ); 
//			cout<<endl; 
//		}
		int a, b, c, d, h, w; 
		cin>>a>>b>>c>>d>>h>>w; 
		que.clear(); 
		getlink(a,b-1,c,d-1,h,0);
		getlink(a,b+w-1,c,d+w-1,h,0);
		getlink(b,a-1,d,c-1,w,1);
		getlink(b,a+h-1,d,c+h-1,w,1); 
		for (auto pp : que) 
			swap(*pp.first, *pp.second); 
	}
	for (int i = 1; i <= n; ++i) {
		int x = p[h[i][0]][0]; 
		for (int j = 1; j <= m; ++j, x=p[x][0]) 
			printf( "%d ", a[x] ); 
		cout<<endl; 
	}
}