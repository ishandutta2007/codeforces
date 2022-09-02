#include<bits/stdc++.h>
#define POP(x) __builtin_popcount(x)
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2005,P=998244353,INF=0X3F3F3F3F;
int n,deg[N];
char mp[N][N];
void rev(int i){
	rep(j,1,n)if(i!=j){
		mp[i][j]^=1,mp[j][i]^=1;
	}
}
int C2(int x){return x*(x-1)/2;}
int chk(){
	sort(deg+1,deg+1+n);
	int sum=0;
	rep(i,1,n-1){
		sum+=deg[i];
		if(sum==C2(i))return 0;
	}
	return 1;
}
void sol1(){
	pair<int,int>res(INF,0);
	rep(s,0,(1<<n)-1){
		rep(i,1,n)if(s>>(i-1)&1)rev(i);
		rep(i,1,n)deg[i]=0;
		rep(i,1,n)rep(j,1,n)deg[i]+=mp[i][j];
		if(chk()){
			if(POP(s)<res.X){
				res=make_pair(POP(s),0);
			}
			if(POP(s)==res.X){
				++res.Y;
			}
		}
		rep(i,1,n)if(s>>(i-1)&1)rev(i);
	}
	if(res.Y){
		rep(i,1,res.X)res.Y*=i;
		printf("%d %d\n",res.X,res.Y);
	}else puts("-1");
}
void rev2(int k1){
	deg[k1]=n-deg[k1]-1;
	rep(k2,1,n)if(k1!=k2){
		deg[k2]-=mp[k2][k1];
		mp[k1][k2]^=1,mp[k2][k1]^=1;
		deg[k2]+=mp[k2][k1];
	}
}
int ans;
void sol2(){
	static int _deg[N];
	memcpy(_deg,deg,sizeof(deg));
	if(chk()){
		puts("0 1");
		return;
	}
	rep(i,1,n){
		memcpy(deg,_deg,sizeof(deg));
		rev2(i);
		ans+=chk();
		rev2(i);
	}
	printf("1 %d\n",ans);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",mp[i]+1);
		rep(j,1,n){
			mp[i][j]-=48;
			deg[i]+=mp[i][j];
		}
	}
	if(n<=6){
		sol1();
	}else{
		sol2();
	}
	return 0;
}