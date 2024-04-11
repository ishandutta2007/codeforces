#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}

int main(){
	int n=ri();
	vector<int> a(n),b(n),p1(n+1),p2(n+1);
	for(int &i:a)rd(i);
	for(int &i:b)rd(i);
	for(int i=0;i<n;i++)p1[a[i]]=i,p2[b[i]]=i;
	vector<int> cnt(n,0);
	for(int i=1;i<=n;i++){
		int x=p1[i]-p2[i];
		if(x<0)x+=n;
		cnt[x]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)ans=max(ans,cnt[i]);
	printf("%i\n",ans);
	return 0;
}