//determined
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int n,d[100010],u[1010],v[1010],w[1010],ou[100010],ov[100010],ow[100010],ops = 0;
vector<int> G[100010];
int r1,r2;
void anyleaf(int num,int fa,int &ans){
	if(d[num] == 1){
		ans = num;
		return;
	}
	for(auto ct:G[num]){
		if(ct == fa)continue;
		anyleaf(ct,num,ans);
		break;
	}
}
void two_leaf(int num,int fa){
	r1 = -1;
	r2 = -1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		if(r1 == -1){
			anyleaf(ct,num,r1);
		}else{
			anyleaf(ct,num,r2);
			return;
		}
	}
}
int main(){
	read(n);
	for(int i=1;i<n;i++){
		read(u[i]);read(v[i]);read(w[i]);
		d[u[i]]+=1;
		d[v[i]]+=1;
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=n;i++){
		if(d[i] == 2){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<n;i++){
		int x = u[i],y = v[i];
		if(d[x]>d[y])swap(x,y);
		if(d[x] == 1){
			if(d[y] == 1){
				ou[ops] = y;ov[ops] = x;ow[ops] = w[i]; ops+=1;
				continue;
			}
			two_leaf(y,x);
			ou[ops] = r1;ov[ops] = x;ow[ops] = w[i]/2; ops+=1;
			ou[ops] = r2;ov[ops] = x;ow[ops] = w[i]/2; ops+=1;
			ou[ops] = r1;ov[ops] = r2;ow[ops] = -w[i]/2; ops+=1;
		}else{
			two_leaf(y,x);
			int r3 = r1,r4 = r2;
			two_leaf(x,y);
			ou[ops] = r1;ov[ops] = r3;ow[ops] = w[i]/2; ops+=1;
			ou[ops] = r2;ov[ops] = r4;ow[ops] = w[i]/2; ops+=1;
			ou[ops] = r2;ov[ops] = r1;ow[ops] = -w[i]/2; ops+=1;
			ou[ops] = r4;ov[ops] = r3;ow[ops] = -w[i]/2; ops+=1;
		}
	}
	cout<<ops<<endl;
	for(int i=0;i<ops;i++){
		cout<<ou[i]<<' '<<ov[i]<<' '<<ow[i]<<endl;
	}
	return 0;
}