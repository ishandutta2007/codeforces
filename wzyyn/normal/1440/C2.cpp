#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
char s[205][205];
struct node{
	int x1,x2,x3,y1,y2,y3;
};
int n,m;
vector<node> v;
void solve(){
	v.resize(0);
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n-2) For(j,1,m){
		if (s[i][j]=='0') continue;
		int x2=i+1,x3=i+1,y2=j,y3=(j==m?j-1:j+1);
		s[i][j]^=1; s[x2][y2]^=1; s[x3][y3]^=1;
		v.PB((node){i,x2,x3,j,y2,y3});
	}
	For(j,1,m-2) For(i,n-1,n){
		if (s[i][j]=='0') continue;
		int x2=i,x3=(i==n?i-1:i+1),y2=j+1,y3=j+1;
		s[i][j]^=1; s[x2][y2]^=1; s[x3][y3]^=1;
		v.PB((node){i,x2,x3,j,y2,y3});
	}
	int id=0;
	if (s[n-1][m-1]=='1') id|=1;
	if (s[n-1][m]=='1') id|=2;
	if (s[n][m-1]=='1') id|=4;
	if (s[n][m]=='1') id|=8;
	For(i,0,15){
		int vv=id;
		if (i&1) vv^=14;
		if (i&2) vv^=13;
		if (i&4) vv^=11;
		if (i&8) vv^=7;
		if (!vv){
			if (i&1) v.PB((node){n-1,n,n,m,m-1,m});
			if (i&2) v.PB((node){n-1,n,n,m-1,m-1,m});
			if (i&4) v.PB((node){n-1,n-1,n,m-1,m,m});
			if (i&8) v.PB((node){n-1,n-1,n,m,m-1,m-1});
		}
	}
	printf("%d\n",v.size());
	for (auto i:v) printf("%d %d %d %d %d %d\n",i.x1,i.y1,i.x2,i.y2,i.x3,i.y3);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}