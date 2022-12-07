#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n,p[1005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	int ans=0;
	for (;;){
		bool flg=0;
		for (int i=1;i<=n;i++)
			if (p[i]!=i) flg=1;
		if (!flg){
			printf("%d\n",ans);
			return;
		}
		for (int i=ans%2+1;i<n;i+=2)
			if (p[i]>p[i+1]) swap(p[i],p[i+1]);
		++ans;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}