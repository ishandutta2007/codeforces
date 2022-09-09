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
const int N=200050;
vector<int> v[N];
int main(){
	int n=ri();
	for(int i=1;i<=n;i++){
		int x=ri();
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				int cnt=0;
				while(x%j==0)x/=j,cnt++;
				v[j].pb(cnt);
			}
		}
		if(x>1)v[x].pb(1);
	}
	ll ans=1;
	for(int i=2;i<N;i++)if(v[i].size()>=n-1){
		sort(v[i].begin(),v[i].end());
		int po=0;
		if(v[i].size()==n)
			po=v[i][1];
		else po=v[i][0];
		while(po--)ans*=i;
		//for(int j:v[i])printf("%i ",j);printf("\n");
	}
	printf("%lld\n",ans);
	return 0;
}