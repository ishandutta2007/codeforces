#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef unsigned long long ull;
constexpr int max_n=200000;
char a[max_n+1],b[max_n+1];
int tr[max_n+1];
int query(int i){
	int ret=tr[i];
	for(; i&=i-1; ret+=tr[i]);
	return ret;
}
#define lowbit(x) (x&(-x))
void update(int i,const int n){
	for(--tr[i]; (i+=lowbit(i))<=n; --tr[i]);
}
il void test(){
	int n;
	scanf("%d\n%s\n%s",&n,a+1,b+1);
	vector<int>pos[26];
	for(int i=n; i; --i)
		pos[a[i]-'a'].push_back(i),tr[i]=lowbit(i);
	ull ans=~0ull;
	ull now=0;
	for(int i=1; i<=n; ++i){
		int nxt1=n+1;
		for(int j=b[i]-'a'-1,tmp; j>=0; --j)
			if(!pos[j].empty())
				(tmp=pos[j].back())<nxt1&&(nxt1=tmp);
		if(nxt1<=n){
//			printf("%d: a %d\n",i,nxt1);
			ull t=now+query(nxt1)-1;
			if(t<ans)
				ans=t;
		}
		if(!pos[b[i]-'a'].empty()&&pos[b[i]-'a'].back()<nxt1){
			int p=pos[b[i]-'a'].back();
//			printf("%d: b %d\n",i,p);
			pos[b[i]-'a'].pop_back();
			update(p,n);
			now+=query(p);
		}
		else
			break;
	}
	if(~ans)
		printf("%llu\n",ans);
	else
		puts("-1");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}