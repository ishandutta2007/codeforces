#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
const int N=200050;
int p[N],m[N],ord[N];
void run(){
	int n;
	scanf("%i",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%i %i",&m[i],&p[i]),ord[i]=i,sum+=p[i];
	sort(ord+1,ord+1+n,[&](int i,int j){return m[i]<m[j];});
	ll ans=0;
	multiset<int> vals;
	int cnt=0;
	for(int i=n,j;i>=1;i=j){
		for(j=i;j>=1 && m[ord[i]]==m[ord[j]];j--)vals.insert(p[ord[j]]);
		int need=m[ord[i]]-j-cnt;
		while(need>0){
			cnt++;
			ans+=*vals.begin();
			vals.erase(vals.begin());
			need--;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--)run();
	return 0;
}