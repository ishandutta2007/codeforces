#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,forbid,cases[200010],grundy[200020],vis[200020] = {0};
bitset<200020> G,O[100];
int main() {
	read(n);read(forbid);
	int m = 0;
	for(int i=0;i<n;i++){
		int a,b,c;
		read(a);read(b);read(c);
		cases[i*2] = b-a;
		cases[i*2+1] = c-b;
		m = max(m,max(b-a,c-b));
	}
	vector<int> pri;
	for(int i=2;i<=m+10;i++){
		if(!vis[i]){
			G.set(i);
			pri.push_back(i);
			for(int j=i+i;j<=m+10;j+=i)vis[j] = 1;
			for(int j=0;j<pri.size() && pri[j]*i<=m;j++){
				G.set(pri[j]*i);
			}
		}
		//if(G[i])cout<<i<<endl;
	}
	//O[0]|=G<<0;
	//cout<<O[0][2]<<endl;
	G[forbid] = 0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<100;j++){
			if(!O[j][i]){
				grundy[i] = j;
				O[j]|=G<<i;
				//cout<<"ORON"<<j<<' '<<i<<endl;
				break;
			}
		}
		//cout<<i<<' '<<grundy[i]<<endl;
	}
	int f = 0;
	for(int i=0;i<n*2;i++)f^=grundy[cases[i]];
	if(f != 0)cout<<"Alice\nBob\n";
	else cout<<"Bob\nAlice\n";
	return 0;
}