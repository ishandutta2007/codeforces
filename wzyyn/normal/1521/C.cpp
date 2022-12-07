#include<bits/stdc++.h>
using namespace std;

int a[10005];
int Query(int a,int b,int c,int d){
	cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	cin>>a;
	return a;
}
int p,ans[10005],n;
void Check(int x,int y){
	int v=Query(1,x,y,n-1);
	if (v==n) p=y;
	else if (v==n-1)
		if (Query(1,y,x,n-1)==n)
			p=x;
}
void solve(){
	scanf("%d",&n);
	p=-1;
	for (int i=1;i+1<=n&&p==-1;i+=2) Check(i,i+1);
	if (p==-1) Check(n-1,n);
	ans[p]=n;
	for (int i=1;i<=n;i++)
		if (i!=p) ans[i]=Query(2,i,p,1);
	printf("!");
	for (int i=1;i<=n;i++)
		printf(" %d",ans[i]);
	puts("");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}