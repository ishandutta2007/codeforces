#include<bits/stdc++.h>
using namespace std;


const int N=400005;
pair<int,int> a[N];
int n,m,id[N],ans[N];
vector<int> q[2];
bool cmp(int x,int y){
	return a[x]<a[y];
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].first);
	for (int i=1;i<=n;i++){
		char s[5];
		scanf("%s",s+1);
		a[i].second=(s[1]=='L'?-1:1);
	}
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	
	for (int i=1;i<=n;i++) ans[i]=-1;
	q[0].resize(0);
	q[1].resize(0);
	for (int i=1;i<=n;i++){
		int x=id[i];
		int p=a[x].first%2;
		if (a[x].second==-1){
			if (!q[p].size())
				q[p].push_back(x);
			else{
				int j=q[p].back();
				q[p].pop_back();
				if (a[j].second==-1)
					ans[x]=ans[j]=(a[x].first+a[j].first)/2;
				else
					ans[x]=ans[j]=(a[x].first-a[j].first)/2;
			}
		}
		else
			q[p].push_back(x);
	}
	for (int i=0;i<2;i++)
		for (;q[i].size()>1;){
			int x=q[i].back();
			q[i].pop_back();
			int y=q[i].back();
			q[i].pop_back();
			if (a[y].second==1)
				ans[x]=ans[y]=(2*m-a[x].first-a[y].first)/2;
			else
				ans[x]=ans[y]=(2*m-a[x].first+a[y].first)/2;
		}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}