#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,k;
vector<int> v[N];
int sub[N];
int q[N],pa[N];
long long d[N];

void prepare(){
	scanf("%d%d",&n,&k);
	k<<=1;
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		sub[x]=1;
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
		
}
void BFS(){
	int top=1,bot=1;
	q[1]=1;
	while (top<=bot){
		int x=q[top++];
		for(auto y:v[x]) if (y!=pa[x]){
			pa[y]=x;
			q[++bot]=y;
		}
	}
}
long long solve(){
	BFS();
	for(int i=n;i>=1;i--){
		int x=q[i];
		for(auto y:v[x]) if (y!=pa[x]){
			d[x]+=d[y]+sub[y];
			sub[x]+=sub[y];
		}
	}
	
	for(int i=1;i<=n;i++){
		int x=q[i];
		for(auto y:v[x]) if (y!=pa[x])
			d[y]=d[x]+k-2*sub[y];
	}
	// for(int i=1;i<=n;i++) cout<<d[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++) cout<<sub[i]<<" \n"[i==n];
	long long ans=-1;
	for(int x=1;x<=n;x++){
		int max_branch=k-sub[x];
		for(auto y:v[x]) if (y!=pa[x])
			max_branch=max(max_branch,sub[y]);
		if (max_branch<=k/2) ans=max(ans,d[x]);
		// cout<<x<<" "<<max_branch<<'\n';
	}
	return ans;
}
int main(){
	prepare();	
	cout<<solve();
}