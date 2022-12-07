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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=2000005;
const int mo=1000000007;
int f[N],g[N];
void mian(){
	int x;
	cin>>x;
	cout<<g[x]<<endl;
}
int main(){
	f[1]=0; f[2]=0;
	For(i,3,N-1){
		g[i]=(2ll*g[i-2]+g[i-1])%mo;
		if (!f[i-2]&&!f[i-1]) g[i]=(g[i]+4)%mo,f[i]=1;
	}
	int T;
	scanf("%d",&T);
	while (T--) mian();
}