#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct atom{
	int type,w,where,pd;
};
vector<atom>A[110000],ans[110000],B;
int compare(atom k1,atom k2){
	return k1.w>k2.w;
}
long long w[110000];
int n,m,k,a[110000],b[110000],now;
struct atom2{
	int where,w;
};
int operator < (atom2 k1,atom2 k2){
	return 1ll*k1.w*w[k2.where]<1ll*k2.w*w[k1.where];
}
int compare1(atom k1,atom k2){
	return k1.type<k2.type;
}
priority_queue<atom2>Q;
int main(){
	scanf("%d%d%d",&k,&n,&m);
	for (int i=1;i<=k;i++) scanf("%I64d",&w[i]);
	for (int i=1;i<=n;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (k1==1){
			if (k3>a[k2]){a[k2]=k3; b[k2]=i;}
		}else if (k1==2) A[k2].push_back((atom){k1,k3,i,0}); else B.push_back((atom){k1,k3,i,k2});
	}
	for (int i=1;i<=k;i++) if (a[i]>w[i]) A[i].push_back((atom){1,a[i]-w[i],b[i],0});
	for (int i=1;i<=k;i++) sort(A[i].begin(),A[i].end(),compare);
	sort(B.begin(),B.end(),compare);
	for (int i=1;i<=k;i++) if (A[i].size()>0){
		a[i]=0; Q.push((atom2){i,A[i][0].w});
	}
	now=0; int tot=0;
	for (int i=1;i<=m;i++){
		if (now==B.size()&&Q.empty()) break;
		tot++;
		if (Q.empty()){
			ans[B[now].pd].push_back((atom){3,0,B[now].where,0}); now++; continue;
		}
		atom2 k1=Q.top(); 
		if (now<B.size()&&k1.w<1ll*(B[now].w-1)*w[k1.where]){
			ans[B[now].pd].push_back((atom){3,0,B[now].where,0}); now++; continue;
		}
		Q.pop();
		ans[k1.where].push_back(A[k1.where][a[k1.where]]);
		w[k1.where]+=A[k1.where][a[k1.where]].w;
		a[k1.where]++;
		if (a[k1.where]==A[k1.where].size()) continue;
		Q.push((atom2){k1.where,A[k1.where][a[k1.where]].w});
	}
	for (int i=1;i<=k;i++) sort(ans[i].begin(),ans[i].end(),compare1);
	cout<<tot<<endl;
	for (int i=1;i<=k;i++)
		for (int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j].where);
	cout<<endl; return 0;
}