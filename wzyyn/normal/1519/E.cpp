#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
struct Frac{
	long long x,y;
	Frac(){}
	Frac(long long _x,long long _y){
		x=_x; y=_y;
	}
	bool operator ==(const Frac &a)const{
		return (__int128)x*a.y==(__int128)y*a.x;
	}
	bool operator <(const Frac &a)const{
		return (__int128)x*a.y<(__int128)y*a.x;
	}
};

const int N=400005;


map<Frac,int> mp;
int n,nd,vis[N];
int tag[N],vise[N];
vector<pair<int,int> > e[N],ans;

void dfs(int x,int fae){
	vis[x]=1;
	for (auto i:e[x])
		if (!vise[i.second]){
			vise[i.second]=1;
			if (vis[i.first]){
				if (tag[x]){
					ans.push_back(make_pair(tag[x],i.second));
					tag[x]=0;
				}
				else
					tag[x]=i.second;
			}
			else{
				dfs(i.first,i.second);
				if (tag[i.first])
					ans.push_back(make_pair(tag[i.first],i.second));
				else if (tag[x]){
					ans.push_back(make_pair(tag[x],i.second));
					tag[x]=0;
				}
				else
					tag[x]=i.second;
			}
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		Frac P1(1ll*(x+y)*b,1ll*y*a);
		Frac P2(1ll*x*b,1ll*y*(a+b));
		if (!mp.count(P1)) mp[P1]=++nd;
		if (!mp.count(P2)) mp[P2]=++nd;
		int i1=mp[P1],i2=mp[P2];
		e[i1].push_back(make_pair(i2,i));
		e[i2].push_back(make_pair(i1,i));
	}
	
	for (int i=1;i<=nd;i++)
		if (!vis[i])
			dfs(i,0);
	printf("%d\n",ans.size());
	for (auto i:ans)
		printf("%d %d\n",i.first,i.second);
}