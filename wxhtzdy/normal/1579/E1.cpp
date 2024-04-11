#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

int F(tuple<int,int,int> x){return get<2>(x)-get<1>(x);}

const int BORDER=200;

int main(){
	int T=read();
	while(T--){
		int n=read();
		int a[n];
		FOR(i,0,n)a[i]=read();
		deque<int> krc;krc.pb(a[0]);
		FOR(i,1,n){
			if(krc[0]>a[i])krc.push_front(a[i]);
			else krc.pb(a[i]);
		}
		for(int e:krc)printf("%d ",e);
		printf("\n");
	}
}