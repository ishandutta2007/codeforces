#include <cstdio>
#include <algorithm>
#include <cstring>
#define mod 1000000007ll
#define cs const
#define max_n 20
#define max_m 20
#define max_siz 20
using namespace std;
typedef long long ll;
int siz;
struct square{
	ll k[max_siz+1][max_siz+1];
	square(){
		memset(k,0,sizeof(k));
	}
	friend square operator*(cs square&a,cs square&b){
		square c;
		for(ll i=1; i<=siz; i++)
			for(ll r=1; r<=siz; r++)
				for(ll p=1; p<=siz; p++)
					c.k[i][r]=(c.k[i][r]+a.k[i][p]*b.k[p][r])%mod;
		return c;
	}
};
square ans,base;
ll mp[max_n+1][max_m+1];
int main(){
	int n,m,q,plk=1,op,x,y,t;
	scanf("%d%d%d",&n,&m,&q);
	siz=n*m,ans.k[1][1]=1;
	for(++q; --q; ){
		scanf("%d%d%d%d",&op,&x,&y,&t);
		for(int i=0; ++i<=siz; )
			for(int r=0,a,b,c,d; ++r<=siz; base.k[i][r]=(mp[a][b]==0&&mp[c][d]==0&&abs(c-a)+abs(d-b)<=1))
				a=(i-1)/m+1,b=(i-1)%m+1,c=(r-1)/m+1,d=(r-1)%m+1;
		for(plk+=(t-=plk); t; t>>=1,base=base*base)
			(t&1)&&(ans=base*ans,1);
		switch(op){
			case 1:
				printf("%lld\n",ans.k[(x-1)*m+y][1]);
				break;
			case 2:
				ans.k[(x-1)*m+y][1]=0,mp[x][y]=1;
				break;
			case 3:
				ans.k[(x-1)*m+y][1]=0,mp[x][y]=0;
				break;
		}
	}
	return 0;
}