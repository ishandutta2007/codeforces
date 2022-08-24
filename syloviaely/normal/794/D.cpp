#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int pd[310000];
struct bian{
	int next,point;
}b[610000];
int n,m,p[310000],len,bo[310000],size[810000],fir[810000];
map<int,int>M[810000];
vector<int>A[310000],B,C;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int getex(int k1,int k2){
	C.clear(); B.clear();
	int now1=0,now2=0;
	while (now1<A[k1].size()&&now2<A[k2].size()){
		if (A[k1][now1]==A[k2][now2]){
			now1++; now2++; continue;
		}
		if (A[k1][now1]<A[k2][now2]){
			B.push_back(A[k1][now1]); now1++;
		} else {
			C.push_back(A[k2][now2]); now2++;
		}
	}
	for (int i=now1;i<A[k1].size();i++) B.push_back(A[k1][i]);
	for (int i=now2;i<A[k2].size();i++) C.push_back(A[k2][i]);
}
int check(int k1,int k2){
	int now1=0,now2=0;
	while (now1<A[k1].size()&&now2<A[k2].size()){
		if (A[k1][now1]==A[k2][now2]){
			now1++; now2++; continue;
		}
		return 0;
	}
	return now1==A[k1].size()&&now2==A[k2].size();
}
void dfs(int k1,int k2,int now,int flag){
	getex(k1,k2);
	if (B.size()==0) return;
	int where=0;
	for (int i=0;i<B.size();i++) 
		if (bo[B[i]]==-1) bo[B[i]]=now+flag,where=B[i];
	if (where==0) return;
	dfs(where,k1,now+flag,flag);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		add(k1,k2);
		A[k1].push_back(k2); A[k2].push_back(k1);
	}
	memset(bo,0xff,sizeof bo);
	for (int i=1;i<=n;i++) A[i].push_back(i);
	for (int i=1;i<=n;i++) sort(A[i].begin(),A[i].end());
	int where=0; bo[1]=n;
	for (int i=0;i<A[1].size();i++){
		int k=A[1][i];
		if (check(1,k)) bo[k]=n;
		else where=k; 
	}
	if (where==0){
		printf("YES\n");
		for (int i=1;i<=n;i++) printf("%d ",bo[i]); return 0;
	}
	bo[where]=n+1;
	for (int i=0;i<A[where].size();i++){
		int k=A[where][i];
		if (check(where,k)) bo[k]=n+1;
	}
	dfs(where,1,n+1,1);
	dfs(1,where,n,-1);
	for (int i=1;i<=n;i++){
		if (bo[i]==-1){
			printf("NO\n"); return 0;
		}
	}
	for (int i=1;i<=n;i++){
		size[bo[i]]++;
		for (int j=0;j<A[i].size();j++){
			if (abs(bo[A[i][j]]-bo[i])>1){
				printf("NO\n"); return 0;
			}
			M[bo[i]][bo[A[i][j]]]++;
		}
	}
	for (int i=1;i<=n*2;i++){
		int totsize=size[i]+size[i+1];
		int tote=M[i][i]+M[i][i+1]+M[i+1][i]+M[i+1][i+1];
		if (tote!=1ll*totsize*totsize){
			printf("NO\n"); return 0;
		}
	}
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",bo[i]);
	return 0;
}