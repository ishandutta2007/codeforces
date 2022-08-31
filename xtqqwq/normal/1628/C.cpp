// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[1005][1005];
bitset<1005> now[1005],st1[1005],xj[1005],yj[1005],res[1005],A[1005];
bool hv[1005];
bool vis[1005][1005];
const int dir[4][2]={0,1,0,-1,1,0,-1,0};

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
		for(int i=1;i<=n;i++){
			now[1][i]=1;
			for(int j=2;j<=n;j++){
				now[j]=now[j-2]^(now[j-1]<<1)^(now[j-1]>>1);
				now[j][0]=now[j][n+1]=0;
			}
			res[i]=now[n];
		}
		now[n+1].reset();
		for(int i=1;i<=n;i++) A[i]=res[i-1]^res[i+1];
		for(int i=1;i<=n;i++) hv[i]=0;
		for(int i=1;i<=n;i++){
			bitset<1005> com;
			com.reset();
			com[i]=1;
			for(int j=1;j<=n;j++){
				if(!A[i][j]) continue;
				if(hv[j]){
					A[i]^=xj[j];
					com^=yj[j];
				}
				else{
					xj[j]=A[i];
					yj[j]=com;
					break;
				}
			}
		}
		bitset<1005> st;
		st1[1].reset();
		for(int i=2;i<=n;i++){
			bitset<1005> tmp=st1[i-1];
			tmp.flip();
			bitset<1005> tmp2=st1[i-2];
			tmp2.flip();
			tmp[0]=tmp[n+1]=tmp2[0]=tmp2[n+1]=0;
			st1[i]=tmp^(tmp2<<1)^(tmp2>>1);
			st1[i][0]=st1[i][n+1]=0;
		}
		st1[n].flip();
		bitset<1005> ans;
		for(int i=1;i<=n;i++){
			if(!st1[n][i]) continue;
			if(hv[i]){
				st1[n]^=xj[i];
				ans^=yj[i];
			}
		}
		int out=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=0;
		for(int i=1;i<=n;i++){
			if(ans[i]){
				for(int j=0;j<4;j++) vis[1+dir[j][0]][i+dir[j][1]]^=1;
				out^=a[1][i];
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!vis[i-1][j]){
					for(int k=0;k<4;k++) vis[i+dir[k][0]][j+dir[k][1]]^=1;
					out^=a[i][j];
				}
			}
		}
		printf("%d\n",out);
		for(int i=1;i<=n;i++) assert(vis[n][i]);
	}
	return 0;
}