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
const int N=200005;
int n,k,x,s[N],lim[N];
vector<int> vec[N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&x),++s[x];
	For(i,1,k) scanf("%d",&lim[i]);
	int pos=0,mx=0;
	Rep(i,k,1){
		if (lim[i]!=lim[i+1]||i==k) pos=0;
		For(j,1,s[i]){
			for (;!pos||vec[pos].size()==lim[i];++pos);
			mx=max(mx,pos),vec[pos].PB(i);
		}
	}
	printf("%d\n",mx);
	For(i,1,mx){
		printf("%d ",vec[i].size());
		for (auto j:vec[i]) printf("%d ",j);
		puts("");
	}
}