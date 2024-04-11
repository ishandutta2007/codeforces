#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
using namespace std;

int l,r;
bool ck(int u){
	bool vis[10];
	memset(vis,0,sizeof(vis));
	while (u){
		int x=u%10;
		if (vis[x]) return 0;
		vis[x]=1;
		u/=10;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>l>>r;
	for (int i=l;i<=r;++i){
		if (ck(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}