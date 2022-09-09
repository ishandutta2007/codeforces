#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}

int main(){
	int n,d,m;rd(n,d,m);
	vector<int> a=rv<int>(n);
	multiset<int> lo,hi;
	ll sum=0;
	int hsz=0;
	for(int i:a){
		if(i<=m)lo.insert(i),sum+=i;
		else hsz++,hi.insert(i);
	}
	int ptr=0;
	ll ans=0;
	while(1){
		int need=(hsz+d)/(d+1);
		while(ptr<need){
			sum+=*hi.rbegin();
			hi.erase(--hi.end());
			ptr++;
		}
		ans=max(ans,sum);
		if(lo.size()==0)break;
		hsz++;
		hi.insert(*lo.begin());
		sum-=*lo.begin();
		lo.erase(lo.begin());
	}
	printf("%lld\n",ans);
	return 0;
}