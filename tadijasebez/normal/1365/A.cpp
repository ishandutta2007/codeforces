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
		int n,m;rd(n,m);
		vector<bool> row(n,true),col(m,true);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(ri())row[i]=false,col[j]=false;
			}
		}
		int r=0,c=0;
		for(int i=0;i<n;i++)if(row[i])r++;
		for(int i=0;i<m;i++)if(col[i])c++;
		if(min(r,c)&1)printf("Ashish\n");
		else printf("Vivek\n");
	}
	return 0;
}