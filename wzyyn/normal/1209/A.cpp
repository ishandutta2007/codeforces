#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,ans,vis[105];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	For(i,1,100) if (vis[i]){
		++ans;
		For(j,1,100/i) vis[i*j]=0;
	}
	printf("%d\n",ans);
}