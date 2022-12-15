#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
int M, N, K, i, j, x, y, a[MN], b[MN], ds[4*MN]; ll ans;
int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}
struct edge{int x, y, w;};
vector<edge> vec;

int main(){
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=N;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=M;i++){
		scanf("%d",&K);
		for(j=1;j<=K;j++){
			scanf("%d",&x);
			ans += a[i]+b[x];
			vec.push_back({i,M+x,a[i]+b[x]});
		}
	}
	sort(vec.begin(),vec.end(),[](edge i,edge j){return i.w>j.w;});
	for(i=1;i<=N+M;i++)
		ds[i] = i;
	for(auto v : vec){
		x = v.x, y = v.y;
		if(fnd(x)^fnd(y)){
			ans -= v.w;
			ds[fnd(x)] = fnd(y);
		}
	}
	printf("%lld\n",ans);
	return 0;
}