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

int Ask(int l,int r){
	printf("? %i ",r-l+1);
	for(int i=l;i<=r;i++)printf("%i ",i);
	printf("\n");
	fflush(stdout);
	return ri();
}
int main(){
	for(int t=ri();t--;){
		int n,k;rd(n,k);
		vector<vector<int>> sub(k,vector<int>());
		for(int i=0;i<k;i++){
			int sz=ri();
			while(sz--)sub[i].pb(ri());
		}
		int mx=Ask(1,n);
		int top=n,bot=1,mid;
		while(top>bot){
			mid=top+bot>>1;
			if(Ask(bot,mid)==mx)top=mid;
			else bot=mid+1;
		}
		vector<int> ans(k);
		for(int i=0;i<k;i++){
			bool has=0;
			for(int j:sub[i])if(j==bot)has=1;
			if(!has)ans[i]=mx;
			else{
				printf("? %i ",n-sub[i].size());
				vector<bool> was(n+1,0);
				for(int j:sub[i])was[j]=1;
				for(int j=1;j<=n;j++)if(!was[j])printf("%i ",j);
				printf("\n");
				fflush(stdout);
				ans[i]=ri();
			}
		}
		printf("! ");
		for(int i=0;i<k;i++)printf("%i ",ans[i]);
		printf("\n");
		fflush(stdout);
		char str[20];
		scanf("%s",str);
	}
	return 0;
}