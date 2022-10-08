#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

const int N=200005;

string s;
int num,cnt;
vector<int>e0,e1,lis[N];

int main(){
	cin>>s;
	for(char c:s)if(c=='0')num++;else num--;
	for(int i=0;i<SZ(s);i++){
		char c=s[i];
		if(c=='0'){
			if(cnt==num){
				if(!e0.size())puts("-1"),exit(0);
				auto s=e0[SZ(e0)-1];e0.pop_back();e1.pb(s);lis[s].pb(i+1); 
			}else e1.pb(++cnt),lis[cnt].pb(i+1);
		}else{
			if(!e1.size())puts("-1"),exit(0);
			auto s=e1[SZ(e1)-1];e1.pop_back();e0.pb(s);lis[s].pb(i+1);
		}
	}
	printf("%d\n",cnt);
	fo(i,1,cnt){
		printf("%u",SZ(lis[i]));
		for(int v:lis[i])printf(" %d",v);puts("");
	}
	return 0;
}