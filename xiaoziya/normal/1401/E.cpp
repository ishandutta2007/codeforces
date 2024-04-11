#include<stdio.h>
#include<vector>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=1000005;
int n,m;
long long ans;
int t[maxn];
vector< pair<int,int> >v[maxn],w[maxn];
void update(int x,int v){
	for(int i=x;i<=1000000;i+=lowbit(i))
		t[i]+=v;
}
int query(int x){
	int res=0;
	if(x<0)
		return 0;
	for(int i=x;i;i-=lowbit(i))
		res+=t[i];
	return res;
}
int main(){
	scanf("%d%d",&n,&m),ans=1;
	for(int i=1,y,l,r;i<=n;i++)
		scanf("%d%d%d",&y,&l,&r),v[l].push_back(make_pair(y,1)),v[r+1].push_back(make_pair(y,-1)),ans+=(r-l==1000000);
	for(int i=1,x,l,r;i<=m;i++)
		scanf("%d%d%d",&x,&l,&r),w[x].push_back(make_pair(l,r)),ans+=(r-l==1000000);
	for(int i=0;i<=1000000;i++){
		for(int j=0;j<v[i].size();j++)
			update(v[i][j].first,v[i][j].second);
		for(int j=0;j<w[i].size();j++)
			ans+=query(w[i][j].second)-query(w[i][j].first-1);
	}
	printf("%lld\n",ans);
	return 0;
}