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
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		string str;cin>>str;
		int pre=0,suf=count(str.begin(),str.end(),'1');
		int ans=str.size();
		for(int i=0;i<str.size();i++){
			if(str[i]=='1')pre++,suf--;
			ans=min(ans,pre+(int)str.size()-i-1-suf);
			ans=min(ans,suf+i+1-pre);
		}
		cout<<ans<<"\n";
	}
	return 0;
}