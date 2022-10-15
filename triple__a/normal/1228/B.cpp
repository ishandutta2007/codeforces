#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
using namespace std;

const int maxn=1007;
const int mo=1e9+7;
int h,w,ans=1;
int ck[maxn][maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>h>>w;
	memset(ck,0,sizeof(ck));
	rep1(i,h){
		int u;
		cin>>u;
		rep1(j,u) ck[i][j]=1;
		ck[i][u+1]=-1;
	}
	rep1(j,w){
		int u;
		cin>>u;
		rep1(i,u){
			if (ck[i][j]==-1){
				cout<<0<<endl;
				return 0;
			}
			ck[i][j]=1;
		}
		if (ck[u+1][j]==1){
			cout<<0<<endl;
			return 0;
		}
		ck[u+1][j]=-1;
	}
	rep1(i,h){
		rep1(j,w){
			if (!ck[i][j]) ans=(ans*2)%mo;
		}
	}
	cout<<ans<<endl;
	return 0;
}