#include <bits/stdc++.h>
using namespace std;
int n,m,p,a[300005][2];
bool check(int x,int y){
	for(int i=1;i<=m;++i)
		if(a[i][0]!=x&&a[i][0]!=y&&a[i][1]!=x&&a[i][1]!=y)
			return 0;
		return 1;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d",&a[i][0],&a[i][1]);
		if(a[i][0]!=a[1][0] && a[i][0]!=a[1][1]&&a[i][1]!=a[1][0]&&a[i][1]!=a[1][1]) p=i;
	}
	if(check(a[1][0],a[1][1])||check(a[1][0],a[p][0])||check(a[1][0],a[p][1]) || check(a[1][1],a[p][0]) || check(a[1][1],a[p][1])) puts("YES");
	else	puts("NO");
}