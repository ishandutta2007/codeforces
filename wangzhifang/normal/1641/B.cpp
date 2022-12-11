#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef const int& ci;
constexpr int max_n=500;
int a[max_n+1],tmp[max_n+1];
vector<pair<int,int> >ans1;
vector<int>ans2;
bool solve(int l,int r,int pr){
//	printf("solve %d %d %d\n",l,r,pr);
	if(l>r)
		return 1;
	int pos;
	for(pos=l; ++pos<=r&&a[pos]!=a[l]; );
//	printf("%d\n",pos);
	if(pos>r)
		return 0;
	for(int i=l; ++i<pos; )
		ans1.emplace_back(pr+pos-l+(i-l),a[i]);
	const int len=pos-l-1;
	ans2.emplace_back((len+1)<<1);
	memcpy(tmp,a+l+1,len<<2);
	for(int i=pos; i>l+1; --i)
		a[i]=tmp[pos-i];
	return solve(l+2,r,((len+1)<<1)+pr);
}
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	ans1.clear();
	ans2.clear();
	if(!solve(1,n,0))
		puts("-1");
	else{
		printf("%llu\n",ans1.size());
		for(auto x:ans1)
			printf("%d %d\n",x.first,x.second);
		printf("%llu\n",ans2.size());
		for(auto x:ans2)
			printf("%d ",x);
		puts("");
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}