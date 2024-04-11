#include<bits/stdc++.h>

using namespace std;

int n,a,b;
int q[100005];
void solve(){
	scanf("%d%d%d",&n,&a,&b);
	if (a+b>n-2||abs(a-b)>1)
		return puts("-1"),void(0);
	int vl=n+1,vr=n+1;
	q[1]=n+1;
	if (a<=b){
		for (int i=1;i<=a+b+1;i++)
			if ((i+1)&1) q[i+1]=++vr;
			else q[i+1]=--vl;
	}
	else{
		for (int i=1;i<=a+b+1;i++)
			if ((i+1)&1) q[i+1]=--vl;
			else q[i+1]=++vr;
	}
	for (int i=a+b+3;i<=n;i++)
		q[i]=(q[i-1]==vl?--vl:++vr);
	for (int i=1;i<=n;i++)
		printf("%d%c",q[i]-vl+1,i==n?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}