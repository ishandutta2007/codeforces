#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int mo=1000000007;
const int N=200005;
int mn[N],n,Q,ans;
map<int,int> mp[N];
set<pii> S[N]; 
void init(){
	For(i,2,N-1)
		For(j,1,(N-1)/i)
			if (!mn[i*j]) mn[i*j]=i;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void insert(int x,int v){
	for (;v!=1;){
		int y=mn[v];
		int key=mp[x][y];
		//cout<<x<<' '<<y<<' '<<key<<' '<<v<<' '<<S[y].size()<<endl;
		if (S[y].size()==n) ans=1ll*ans*power(y,mo-1-(*S[y].begin()).fi)%mo;
		if (key!=0) S[y].erase(pii(key,x));
		for (;v%y==0;v/=y,++key);
		mp[x][y]=key;
		S[y].insert(pii(key,x));
		if (S[y].size()==n) ans=1ll*ans*power(y,(*S[y].begin()).fi)%mo;
	}
}
int main(){
	init();
	scanf("%d%d",&n,&Q);
	ans=1;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		insert(i,x);
	}
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
		printf("%d\n",ans);
	}
}