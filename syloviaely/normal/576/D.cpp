#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<bitset>
#include<vector>
#include<queue>
using namespace std;
struct matrix{
	bitset<155>A[155],B[155];
}ans,B,now,C;
int n,m;
struct atom{
	int u,v,t;
	void scan(){
		scanf("%d%d%d",&u,&v,&t); u--; v--;
	}
}x[160];
int compare(atom k1,atom k2){
	return k1.t<k2.t;
}
matrix operator * (const matrix &k1,const matrix &k2){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			int k3=(k1.A[i]&k2.B[j]).count();
			if (k3>1) k3=1;
			B.A[i][j]=k3; B.B[j][i]=k3;
		}
	return B;
}
const int inf=2e9;
int d[160];
queue<int>Q;
vector<int>go[160];
int solve(int k){
	for (int i=0;i<n;i++) go[i].clear(),d[i]=inf;
	for (int i=1;i<=k;i++){
		go[x[i].u].push_back(x[i].v); //cout<<"link "<<x[i].u<<" "<<x[i].v<<endl;
	}
	for (int i=0;i<n;i++) if (ans.A[0][i]) d[i]=x[k].t,Q.push(i);
	while (!Q.empty()){
		int k=Q.front(); //cout<<"asd "<<k<<" "<<d[k]<<endl;
		for (int i=0;i<go[k].size();i++){
			int j=go[k][i];
			if (d[j]==inf){
				d[j]=d[k]+1; Q.push(j);
			}
		}
		Q.pop();
	}
	return d[n-1];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) x[i].scan();
	sort(x+1,x+m+1,compare);
	for (int i=0;i<n;i++) ans.A[i][i]=1,ans.B[i][i]=1;
	int an=inf;
	for (int i=1;i<=m;i++){
		int k1=x[i].t-x[i-1].t; C=now;
		while (k1){
			if (k1&1) ans=ans*C; C=C*C; k1>>=1;
		}
		an=min(an,solve(i));
	/*	cout<<"fa "<<i<<" "<<x[i].u<<" "<<x[i].v<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++) cout<<ans.A[i][j]<<" "; cout<<endl;}*/
		now.A[x[i].u][x[i].v]=1; now.B[x[i].v][x[i].u]=1;
	//	for (int i=0;i<n;i++){
	//		for (int j=0;j<n;j++) cout<<now.A[i][j]<<" "; cout<<endl;}
	}
	if (an!=inf) printf("%d\n",an); else printf("Impossible\n");
	return 0;
}