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
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

const int N=200050;
const int L=20;
int a[N];
queue<int> has_bit[L];
void Add(int i){
	for(int j=0;j<L;j++){
		if(a[i]>>j&1)has_bit[j].push(i);
	}
}
void Del(int bit,int i){
	while(has_bit[bit].size()&&(!(a[has_bit[bit].front()]>>bit&1)||has_bit[bit].front()<=i))has_bit[bit].pop();
}
int main(){
	int n=ri();
	for(int i=1;i<=n;i++){
		a[i]=ri();
		Add(i);
	}
	for(int i=1;i<=n;i++){
		//Del(i);
		for(int j=L-1;~j;j--){
			if(!(a[i]>>j&1)){
				Del(j,i);
				if(has_bit[j].size()){
					//int pos=*has_bit[j].begin();
					//Del(pos);
					int pos=has_bit[j].front();
					has_bit[j].pop();

					int x=a[i],y=a[pos];
					a[i]=x|y;
					a[pos]=x&y;
					Add(pos);
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=(ll)a[i]*a[i];
	printf("%lld\n",ans);
	return 0;
}