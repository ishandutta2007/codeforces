#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,q;
int lst[N],to[N],nxt[N],len[N],ec;
inline void ae(int x,int y,int z){
	to[++ec]=y,nxt[ec]=lst[x],len[ec]=z,lst[x]=ec;	
}
int mark[N];
int ans[N];
void solve(int k){
	fill(mark+1,mark+n+1,-1);
	for(int x=1;x<=n;x++){
		for(int i=lst[x];i;i=nxt[i]){
			int y=to[i];
			if((len[i]&1<<k)==0)mark[x]=mark[y]=0;	
		}
	}
	for(int x=1;x<=n;x++){
		if(mark[x]==1)continue;
		bool flag=1;
		for(int i=lst[x];i;i=nxt[i]){
			if((len[i]&1<<k)==0)continue;
			int y=to[i];
			if(mark[y]==0)flag=0;
		}
		if(!flag)mark[x]=1;
		else{
			mark[x]=0;
			for(int i=lst[x];i;i=nxt[i]){
				if((len[i]&1<<k)==0)continue;
				int y=to[i];
				mark[y]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)if(mark[i])ans[i]|=1<<k;
}
int main(){
	n=in(),q=in();
	while(q--){
		int x=in(),y=in(),z=in();
		if(x>y)swap(x,y);
		ae(x,y,z);	
	}
	for(int i=0;i<30;i++)solve(i);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}