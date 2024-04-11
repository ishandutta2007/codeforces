#include<bits/stdc++.h>
#define ll long long
#define N 300005

char buf[1<<25],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char obuf[1<<25],*O=obuf;
#define putchar(c) (*O++=c)
inline void wr(ll x){
	if(x>9)
		wr(x/10);
	putchar(x%10+'0');
}

int T;

int n,m;

std::unordered_map<int,int> cnt;
std::unordered_set<ll> vis;
#define num(x,y) (1ll*(x)*(n+1)+(y))

std::vector<int> V[N];

int main(){
	rd(T);
	while(T--){
		cnt.clear(),vis.clear();
		rd(n),rd(m);
		for(int i=1;i<=n;i++){
			int x;
			rd(x);
			cnt[x]++;
			vis.insert(num(x,x));
		}
		for(int i=1;i<=m;i++){
			int x,y;
			rd(x),rd(y);
			vis.insert(num(x,y)),vis.insert(num(y,x));
		}
		ll ans=0;
		int B=1;
		while(B*B<n)
			B++;
		for(auto [x,y]:cnt)
			if(y<=B)
				V[y].push_back(x);
		for(int i=1;i<=B;i++)
			std::sort(V[i].begin(),V[i].end(),std::greater<int>());
		for(auto [x,y]:cnt)
			if(y<=B){
				for(int i=1;i<=B;i++)
					for(auto u:V[i]) if(!vis.count(num(x,u))){
						ans=std::max(ans,1ll*(x+u)*(y+i));
						break;
					}
			}
			else
				for(auto [u,v]:cnt) if(!vis.count(num(x,u)))
					ans=std::max(ans,1ll*(x+u)*(y+v));
		wr(ans),putchar('\n');
		for(int i=1;i<=B;i++)
			V[i].clear();
	}
	fwrite(obuf,O-obuf,1,stdout);
}