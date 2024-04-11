#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int S=320;
int n,m,k,a[N];
ll pref[N];
struct Query{
	int l,r,id;
	Query(){}
	bool operator<(Query b) const{
		return (r/S<b.r/S)||(r/S==b.r/S&&l<b.l);
	}
}Q[N];
ll ans[N],tmp;
int cnt[N*22];
void Add(ll x){
	tmp+=cnt[x^k];
	cnt[x]++;
}
void Rem(ll x){
	cnt[x]--;
	tmp-=cnt[x^k];
}
int main(){
	scanf("%i%i%i",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),pref[i]=pref[i-1]^a[i];
	for(int i=1;i<=m;i++){
		scanf("%i%i",&Q[i].l,&Q[i].r);
		--Q[i].l;Q[i].id=i;
	}
	sort(Q+1,Q+m+1);
	int l=0,r=-1;
	for(int i=1;i<=m;i++){
		while(r<Q[i].r)Add(pref[++r]);
		while(r>Q[i].r)Rem(pref[r--]);
		while(l<Q[i].l)Rem(pref[l++]);
		while(l>Q[i].l)Add(pref[--l]);
		ans[Q[i].id]=tmp;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}