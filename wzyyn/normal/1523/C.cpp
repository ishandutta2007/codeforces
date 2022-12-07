#include<bits/stdc++.h>
using namespace std;

int n,q[1005];
void solve(){
	scanf("%d",&n);
	*q=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x==1) q[++*q]=x;
		else{
			for (;q[*q]!=x-1;--*q);
			++q[*q];
		}
		for (int j=1;j<=*q;j++)
			printf("%d%c",q[j],j==*q?'\n':'.');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}