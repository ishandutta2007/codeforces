#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int m,n;
double ans = 0;
cin >> n >> m;
int *v=new int[n];
int *e=new int[n*n];
for(int i=0; i<n; i++){
	int x;
	cin >> x;
	v[i]=x;
}
for(int j=0; j<m; j++){
	int a,b,y;
	
	cin >> a >> b >> y;
	a--; b--;
	e[a*n+b]=y;
	e[b*n+a]=y;
	double k = v[a];
	double l = v[b];
	double p = y;
	double q = (k+l)/p;
	if(q>ans) ans=q;

}
printf("%.10f", ans);
//cout << ans;
  return 0;
}