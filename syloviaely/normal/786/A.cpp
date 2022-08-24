#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int pd[10000][2],n,d[10000][2];
vector<int>A[2];
void print(int k1,int k2,int k3){
	if (pd[k1][k2]!=-1) return;
//	cout<<"print "<<k1<<" "<<k2<<" "<<k3<<endl;
	pd[k1][k2]=k3;
	if (k3==0){
		for (int i=0;i<A[k2^1].size();i++){
			int w=(k1-A[k2^1][i]+n)%n; if (w==0) continue;
			print(w,k2^1,1);
		}
	} else {
		for (int i=0;i<A[k2^1].size();i++){
			int w=(k1-A[k2^1][i]+n)%n; if (w==0) continue;
			d[w][k2^1]--;
			if (d[w][k2^1]==0) print(w,k2^1,0);
		}
	}
}
void getans(){
	memset(pd,0xff,sizeof pd);
	for (int i=0;i<n;i++) d[i][0]=A[0].size(),d[i][1]=A[1].size();
	print(0,0,0);
	print(0,1,0);
	for (int i=1;i<n;i++) if (pd[i][0]==-1) printf("Loop "); else if (pd[i][0]==0) printf("Lose "); else printf("Win ");
	putchar('\n');
	for (int i=1;i<n;i++) if (pd[i][1]==-1) printf("Loop "); else if (pd[i][1]==0) printf("Lose "); else printf("Win ");
	putchar('\n');
}
int main(){
	scanf("%d",&n);
	int k1; scanf("%d",&k1);
	for (;k1;k1--){
		int k2; scanf("%d",&k2); A[0].push_back(k2);
	}
	scanf("%d",&k1);
	for (;k1;k1--){
		int k2; scanf("%d",&k2); A[1].push_back(k2);
	}
//	cout<<A[0].size()<<" "<<A[1].size()<<endl;
	getans();
	return 0;
}