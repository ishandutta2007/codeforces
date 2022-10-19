using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define F(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define ll long long
int minx=1e9,miny=1e9,maxx,maxy;
int n,m,ans,x[100001],y[100001];
int tot;
char s[100001];
bool pg[501][501];
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%s",s);
		for(int j=0;j<m;j++) {
			if(s[j]=='B') {
				x[++tot]=i;y[tot]=j+1;
				minx=min(minx,x[tot]);miny=min(miny,y[tot]);
				maxx=max(maxx,x[tot]);maxy=max(maxy,y[tot]);
			}
		}
	}
	int mx=minx,my=miny;
	int it=max(maxx-minx,maxy-miny)+1;
	bool flag=0;
	ans=it;
	if(tot==0) {
		puts("1");return 0;
	}
	int i=ans;
	for(int minx=1;minx<=n;minx++) 
	for(int miny=1;miny<=m;miny++){
		memset(pg,0,sizeof(pg));
		if(minx+i-1>n||miny+i-1>m) break;
		for(int j=1;j<=i;j++) {
			for(int k=1;k<=i;k++) {
				pg[minx+j-1][miny+k-1]=1;
			}
		}
		bool can=0;
		for(int j=1;j<=tot;j++) {
			if(!pg[x[j]][y[j]]) {
				can=1;break;
			}
		}
		if(!can) {
			flag=1;break;
		}
	}
	if(!flag) {
		puts("-1") ;return 0;
	}
	cout<<ans*ans-tot<<endl;
}