#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

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

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

const int N=100005;

bitset<N>v[30],ret;
char s[N],t[N];
int n,q,o,l,r,a;

int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&q);
	fo(i,1,n)v[s[i]-'a'][i]=1;
	while(q--){
		scanf("%d",&o);
		if(o==1){
			scanf("%d%s",&l,t);
			v[s[l]-'a'][l]=0,s[l]=*t,v[s[l]-'a'][l]=1;
		}else{
			scanf("%d%d%s",&l,&r,t);
			ret=0;ret=~ret;r=r-strlen(t)+1;
			if(r<l){puts("0");continue;}
			fo(i,0,strlen(t)-1)ret&=v[t[i]-'a']>>i;
			ret>>=l;a=ret.count();
			ret>>=r-l+1;a-=ret.count();
			printf("%d\n",a);
		}
	}
	return 0;
}