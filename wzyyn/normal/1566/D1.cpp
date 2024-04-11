#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,m,a[N],id[N];
bool cmp(int x,int y){
	return a[x]==a[y]?x<y:a[x]<a[y];
}
bool cmp2(int x,int y){
	return a[x]==a[y]?x>y:a[x]<a[y];
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
		scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n*m+1,cmp);
	int ans=0;
	for (int l=1,r=m;l<=n*m;l+=m,r+=m){
		sort(id+l,id+r+1,cmp2);
		for (int i=l;i<=r;i++)
			for (int j=i+1;j<=r;j++)
				ans+=(id[j]>id[i]);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}