#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,t,A[4000000],x[1100000],y[1100000],len;
int pd[4000000][2],ne[4000000][2],f[4000000][2],T[4000000][2];
vector<int>wayA;
vector<pair<int,int> >wayB;
void printway(int now){
	for (int i=len+1;i;i--){
		if (T[i][now]) wayA.push_back(A[i]),now^=1;
		if (pd[i][now]) wayB.push_back(make_pair(A[i]-f[i][now],now));
	}
	sort(wayA.begin(),wayA.end());
	sort(wayB.begin(),wayB.end());
	printf("%d\n",(int)(wayA.size()));
	for (int i=0;i<wayA.size();i++) printf("%d ",wayA[i]); printf("\n");
	printf("%d\n",(int)(wayB.size()));
	for (int i=0;i<wayB.size();i++) printf("%d %d\n",wayB[i].first,wayB[i].second+1);
}
int main(){
	scanf("%d%d%d%d",&n,&m1,&m2,&t); A[++len]=0;
	for (int i=1;i<=m1;i++){
		int k1; scanf("%d",&k1);
		A[++len]=k1;
		A[++len]=k1+1;
		A[++len]=k1-1; x[i]=k1;
	}
	for (int i=1;i<=m2;i++){
		int k1; scanf("%d",&k1);
		A[++len]=k1;
		A[++len]=k1+1;
		A[++len]=k1-1; y[i]=k1;
	}
	sort(A+1,A+len+1); int pre=len; len=1;
	for (int i=2;i<=pre;i++)
		if (A[i]!=A[len]) A[++len]=A[i];
	int now=1;
	for (int i=1;i<=m1;i++){
		while (A[now]!=x[i]) now++; pd[now][0]=1;
	}
	now=1;
	for (int i=1;i<=m2;i++){
		while (A[now]!=y[i]) now++; pd[now][1]=1;
	}
	/*for (int i=1;i<=len;i++) cout<<A[i]<<" "; cout<<endl;
	for (int i=0;i<2;i++){
		for (int j=1;j<=len;j++) cout<<pd[j][i]<<" "; cout<<endl;
	}*/
	for (int i=0;i<2;i++){
		ne[len+1][i]=len+1;
		for (int j=len;j;j--)
			if (pd[j+1][i]) ne[j][i]=j+1; else ne[j][i]=ne[j+1][i];
	}
	memset(f,0xff,sizeof f); f[1][0]=0;
	for (int i=1;i<=len;i++){
		if (pd[i][0]==0){
			if (min(f[i][1],t)>f[i][0]){
				f[i][0]=min(f[i][1],t); T[i][0]=1;
			}
		}
		if (pd[i][1]==0){
			if (min(f[i][0],t)>f[i][1]){
				f[i][1]=min(f[i][0],t); T[i][1]=1;
			}
		}
		if (f[i][0]!=-1){
			if (pd[i+1][0]){
				if (f[i][0]+A[i+1]-A[i]>t) {f[i+1][0]=f[i][0]+A[i+1]-A[i]-t;}
			} else f[i+1][0]=f[i][0]+A[i+1]-A[i]; 
		}
		if (f[i][1]!=-1){
			if (pd[i+1][1]){
				if (f[i][1]+A[i+1]-A[i]>t) {f[i+1][1]=f[i][1]+A[i+1]-A[i]-t;}
			} else f[i+1][1]=f[i][1]+A[i+1]-A[i]; 
		}
	//	cout<<f[i][0]<<" "<<f[i][1]<<" "<<T[i][0]<<" "<<T[i][1]<<endl;
	}
	if (f[len+1][0]==-1&&f[len+1][1]==-1){
		printf("No\n"); return 0;
	}
	printf("Yes\n");
	if (f[len+1][0]==-1) printway(1); else printway(0);
}