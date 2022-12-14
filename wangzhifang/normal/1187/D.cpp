#include <cstdio>
#include <vector>
using namespace std;
#define max_n 300000
#define lowbit(x) (x&-x)
int a[max_n+1],b[max_n+1],p[max_n+1],f[max_n+1];
vector<int>v[max_n+1];
void update(int x,const int&k,const int&n){
	for(; x<=n; x+=lowbit(x))
		f[x]=max(f[x],k);
}
int query(int x){
	int ret=0;
	for(; x; x^=lowbit(x))
		ret=max(ret,f[x]);
	return ret;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int n; t; --t){
		scanf("%d",&n);
		bool flg=0;
		for(int i=1; i<=n; ++i){
			scanf("%d",a+i);
			v[a[i]].clear();
		}
		for(int i=1; i<=n; ++i){
			scanf("%d",b+i);
			v[b[i]].push_back(i);
		}
		for(int i=n; i; --i){
			if(!v[a[i]].size())
				flg=1;
			else
				p[i]=v[a[i]][v[a[i]].size()-1],v[a[i]].pop_back();
		}
		for(int i=1; i<=n; ++i)
			f[i]=0;
		for(int i=1; i<=n; ++i){
			if(query(a[i]-1)>p[i])
				flg=1;
			update(a[i],p[i],n);
		}
		puts(flg?"NO":"YES");
	}
	return 0;
}