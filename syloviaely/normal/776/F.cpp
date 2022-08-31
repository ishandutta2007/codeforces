#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<map>
using namespace std;
set<int>go[110000];
map<pair<int,int>,int>M;
struct bian{
	int next,point;
}b[210000];
int n,m,N,a[110000],p[110000],len;
vector<int>way[110000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
//	cout<<"add "<<k1<<" "<<k2<<endl;
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2,int s){
	if (k1==s) return;
	way[N].push_back(k1);
	set<int>::iterator k=go[k1].lower_bound(k2);
	if (k==go[k1].begin()) k=go[k1].end();
	k--; int ne=(*k); go[k1].erase(k);
	M[make_pair(ne,k1)]=N;
	dfs(ne,k1,s);
}
int compare(int k1,int k2){
	return k1>k2;
}
int compare1(int k1,int k2){
	return way[k1]<way[k2];
}
int ans[110000],pd[110000],size[110000],where,now;
int dfs1(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j==k2||pd[j]) continue;
		size[k1]+=dfs1(j,k1);
	}
	return size[k1];
}
void dfs2(int k1,int k2){
	int num=n-size[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]||j==k2) continue;
		dfs2(j,k1); num=max(num,size[j]);
	}
	if (num<now){
		where=k1; now=num;
	}
}
void getans(int k1,int k2){
	n=dfs1(k1,0); now=n; where=k1; dfs2(k1,0); int k=where; pd[k]=1; ans[k]=k2;
//	cout<<"fa "<<k1<<" "<<k2<<" "<<k<<endl;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point; //cout<<"asd "<<j<<" "<<pd[j]<<endl;
		if (pd[j]==0) getans(j,k2+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int ne=(i%n+1); go[ne].insert(i); go[i].insert(ne);
	}
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2); go[k1].insert(k2); go[k2].insert(k1);
	}
	int now=1;
	while (now<=n){
		if (go[now].size()==0){
			now++; continue;
		}
		set<int>::iterator k=go[now].begin();
		int k1=(*k); go[now].erase(k);
		N++; way[N].push_back(now); M[make_pair(k1,now)]=N;
		dfs(k1,now,now);
		sort(way[N].begin(),way[N].end(),compare);
	}
	for (int i=1;i<=N;i++) a[i]=i;
	sort(a+1,a+N+1,compare1);
	for (map<pair<int,int>,int>::iterator k=M.begin();k!=M.end();k++){
		int k1=(*k).first.first,k2=(*k).first.second;
		if (k2==k1%n+1||k1==k2%n+1) continue;
		if (k1<k2) add(M[make_pair(k1,k2)],M[make_pair(k2,k1)]);
	}
	int flag=0;
/*	for (int i=1;i<=N;i++){
		cout<<"fa "<<endl;
		for (int j=0;j<way[i].size();j++) cout<<way[i][j]<<" "; cout<<endl;
	}*/
	for (int i=1;i<=N;i++)
		if (pd[i]==0){
			int k=dfs1(i,0); if (k==1&&flag==0) {flag=i; continue;}
			getans(i,1);
		}
//	cout<<flag<<endl;
	for (int i=1;i<=N;i++){
		if (a[i]==flag) continue; printf("%d ",ans[a[i]]);
	}
	printf("\n");
}