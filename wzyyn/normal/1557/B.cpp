#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=100005;
int n,k,a[N],id[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
void solve(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	int s=1;
	for (int i=1;i<n;i++) s+=(id[i+1]!=id[i]+1);
	puts(s>k?"No":"Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}