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

const int N=1000050;
char s[N],t[N];
int main(){
	int n=ri();
	scanf("%s %s",s+1,t+1);
	vector<int> a;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'&&t[i]=='0')a.pb(1);
		if(s[i]=='0'&&t[i]=='1')a.pb(-1);
	}
	int pos=0,neg=0;
	for(int i:a){
		if(i==1){
			if(neg)neg--,pos++;
			else pos++;
		}else{
			if(pos)pos--,neg++;
			else neg++;
		}
	}
	if(accumulate(a.begin(),a.end(),0)==0)printf("%i\n",pos+neg);
	else printf("-1");
	return 0;
}