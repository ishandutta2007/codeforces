#include<bits/stdc++.h>

using namespace std;

const int N=200005;

char s[N];
int a[N],id[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int solve(int n){
	for (int i=1;i<=n;i++)
		a[i]=a[i-1]+(s[i]=='1'?1:-1);
	for (int i=0;i<=n;i++) id[i]=i;
	sort(id,id+n+1,cmp);
	int v=1<<30,p=0,re=0;
	for (int i=0;i<=n;i++){
		for (;a[id[p]]<a[id[i]];++p) v=min(v,id[p]);
		if (v<id[i]) re=max(re,(id[i]-v-(a[id[i]]-a[v]))/2);
	}
	return re;
}
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int re=solve(n);
	for (int i=1;i<=n;i++) s[i]^=1;
	re=max(re,solve(n));
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}