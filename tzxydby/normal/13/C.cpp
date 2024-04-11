#include<bits/stdc++.h>
//#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
#define PB pop_back
#define PF pop_front
#define np next_permutation
#define eb emplace_back
#define pb push_back
#define bf push_front
#define mp make_pair
#define s second
#define f first
#define mt make_tuple
#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)
#define forn(i, a) for(int i=0; i<a; i++)
#define Forn(i, a) for(int i=1; i<=a; i++)
#define INF 1e9
#define memINF 127
#define inf 1e18
#define all(x) x.begin(), x.end()
#define MOD 1e9+7 

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef unsigned int uint;

using namespace std;

inline int in() 
{
    int x=0, c;
    for(; (uint)((c=getchar())-'0')>=10;) 
	{ 
		if(c=='-') 
			return -in(); 
		if(!~c)
			throw ~0; 
	}
    do 
	{ 
		x=(x<<3)+(x<<1)+(c-'0'); 
	} 
	while((uint)((c=getchar())-'0')<10);
    return x;
}
inline int gcd(int a, int b){if(a>b) swap(a, b); return a==0?b:gcd(b%a, a);}
inline int lcm(int a, int b){return a*b/gcd(a, b);}

int N, a[5005];
vector<int> lisa;
ll dp[2][5005], res=inf;

int main()
{
	N=in();
	lisa.resize(N);
	forn(i, N)
		a[i]=in(), lisa[i]=a[i];
	sort(all(lisa));
	lisa.resize(unique(all(lisa))-lisa.begin());
	
	memset(dp, memINF, sizeof(dp));
	forn(i, lisa.size()+1)
		dp[0][i]=abs(a[0]-lisa[i]);
	Forn(i, N-1)
	{
		ll base=dp[!(i&1)][0];
		forn(j, lisa.size())
		{
			base=min(base, dp[!(i&1)][j]);
			dp[i&1][j]=base+abs(a[i]-lisa[j]);
		}
	}
	forn(j, lisa.size())
		res=min(res, dp[(N-1)&1][j]);
	printf("%I64d\n", res);
	return 0;
}