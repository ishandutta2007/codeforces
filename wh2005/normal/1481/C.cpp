#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int T,n,m,a[N],b[N],c[N];
#define vi vector<int >
vi v[N],e[N],t;int p[N];
bool check(){
	for(int i=1;i<=m;i++) a[p[i]]=c[i];
	for(int i=1;i<=n;i++) if(a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=m;i++) scanf("%d",&c[i]);
		for(int i=1;i<=n;i++){
			v[i].clear();e[i].clear();
		}
		t.clear();
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]) v[b[i]].push_back(i);
		for(int i=1;i<=n;i++)
			if(a[i]==b[i]) e[a[i]].push_back(i);
		int flag=1;
		for(int i=m;i>=1;i--){
			int x=c[i];
			if(v[x].size()>0){
				int u=v[x][v[x].size()-1];v[x].pop_back();
				p[i]=u;t.push_back(u);
			}
			else if(e[x].size()>0){
				int u=e[x][e[x].size()-1];e[x].pop_back();
				p[i]=u;t.push_back(u);
			}
			else if(t.size()>0){
				int u=t[t.size()-1];p[i]=u;
			}
			else{
				flag=0;break;
			} 
		}
		if(!flag||!check()) printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<=m;i++) printf("%d ",p[i]);puts("");
		}
	}
	return 0;
}