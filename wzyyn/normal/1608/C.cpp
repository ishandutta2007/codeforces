#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,a[N],b[N];
int id1[N],id2[N];
int pos[N],pre[N];
int re[N];

bool cmpa(int x,int y){
	return a[x]>a[y];
}
bool cmpb(int x,int y){
	return b[x]>b[y];
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),id1[i]=i;
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]),id2[i]=i;
	sort(id1+1,id1+n+1,cmpa);
	sort(id2+1,id2+n+1,cmpb);
	for (int i=1;i<=n;i++)
		pos[id1[i]]=i,pre[i]=-1;
	for (int i=2;i<=n;i++)
		pre[pos[id2[i-1]]]=pos[id2[i]];
	int ans=1;
	for (int i=2;i<=n;i++)
		if (pre[i]!=-1&&pre[i]<=ans) ans=i;
	for (int i=1;i<=n;i++)
		re[i]=0;
	for (int i=1;i<=ans;i++)
		re[id1[i]]=1;
	for (int i=1;i<=n;i++){
		printf("%d",re[i]);
	}
	puts("");

}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}