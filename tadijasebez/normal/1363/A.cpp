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
	for(int t=ri();t--;){
		int n,x;rd(n,x);
		int cnt[2]={0,0};
		for(int i=0;i<n;i++)cnt[ri()&1]++;
		if(!cnt[1]){printf("No\n");continue;}
		cnt[1]--;x--;
		while(x>1&&cnt[1]>1)x-=2,cnt[1]-=2;
		while(cnt[0]&&x)x--,cnt[0]--;
		if(x==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}