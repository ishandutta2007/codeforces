#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}


int n,m1,m,a[2050],dp[2050][2050],vis[2050][2050] = {0},diff[2050],loc[550];

int solve(int l,int r){
	int cdiv[2050];
	if(l>=r)return 1;
	if(vis[l][r])return dp[l][r];
	set0(cdiv);
	set0(loc);
	for(int i=l;i<=r;i++){
		if(loc[a[i]]){
			cdiv[loc[a[i]]+1]+=1;
			cdiv[i+1]-=1;
		}else{
			loc[a[i]] = i;
		}
	}
	for(int i=l;i<=r+1;i++){
		cdiv[i]+=cdiv[i-1];
		//if(l ==1 && r == 17)cout<<"cdiv"<<' '<<i<<' '<<cdiv[i]<<endl;
	}
	vis[l][r] = 1;
	int mi = 2000,mlp,mrp;
	for(int j=l;j<=r;j++){
		if(a[j]<mi){
			mi = a[j];
			mlp = j;
		}
		if(a[j]<=mi)mrp = j;
	}
	int cmul = 1,la = mlp-1;
	for(int j=mlp;j<=mrp;j++){
		if(a[j] == mi){
			if(j-la>1){
				cmul = mul(cmul,solve(la+1,j-1));
				//cout<<"CUSE"<<la+1<<' '<<j-1<<' '<<solve(la+1,j-1)<<endl;
			}
			la = j;
		}
	}
	int cl = 0,cr = 0;
	//cout<<"lmlp"<<l<<' '<<mlp<<endl;
	for(int hf = l;hf<=mlp;hf++){
		
		if(cdiv[hf] == 0){
			cl = add(cl,mul(solve(l,hf-1),solve(hf,mlp-1)));
		}
	}
	for(int hf = mrp+1;hf<=r+1;hf++){
//	if(!cdiv[hf] && l ==1 && r == 17)cout<<"hf"<<hf<<' '<<cdiv[hf]<<endl;
		if(cdiv[hf] == 0) cr = add(cr,mul(solve(mrp+1,hf-1),solve(hf,r)));
	}
	dp[l][r] = mul(cmul,mul(cl,cr));
//	cout<<l<<' '<<r<<' '<<dp[l][r]<<' '<<cl<<' '<<cr<<endl;
	return dp[l][r];
}

int main() {
	read(n);read(m1);
	for(int i=1;i<=m1;i++){
		int cur;
		read(cur);
		if(m == 0 || cur!=a[m]){
			a[m+1] = cur;
			m+=1;
		}
		if(m>1300){
			cout<<0<<endl;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
	//	cout<<a[i]<<' ';
		int cmin = a[i];
		for(int j=i+1;j<=m;j++){
			if(a[j] == a[i] && cmin<a[i]){
				cout<<0<<endl;
				return 0;
			}
			cmin = min(cmin,a[j]);
		}
	}
	//cout<<endl;
	cout<<solve(1,m)<<endl;
	return 0;
}