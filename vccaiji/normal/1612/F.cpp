#include<bits/stdc++.h>
using namespace std;
int n,m;
int q;
set<int> u[210000];
int o[210000];
int oo[210000];
int main(){
	cin>>n>>m>>q;bool r=0;
	if(n>m)swap(n,m),r=1;
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		if(r)swap(a,b);
		u[a].insert(b);
	}
	int ans=0;
	o[1]=1;
	while(1){
		if(o[n]==m)break;
		ans++;
		for(int i=1;i<=n;i++){
			if(o[i])oo[i]=min(m,i+o[i]+(u[i].find(o[i])!=u[i].end() ? 1 : 0));
			else oo[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(o[i]){
				int t=min(n,i+o[i]+(u[i].find(o[i])!=u[i].end() ? 1 : 0));
				oo[t]=max(oo[t],o[i]);
			}
		}
		for(int i=1;i<=n;i++)o[i]=oo[i];
	}
	cout<<ans;
	return 0;
}