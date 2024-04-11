#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int T,lgn;
LL pw[25],val[25];
char n[25],s[25][15];
map<tuple<int,LL,LL,int>,LL>mp;
LL sol(char*n,char(*s)[15],int lgn,LL cost,LL cost_first,int opt){
	if(mp.count({lgn,cost,cost_first,opt}))return mp[{lgn,cost,cost_first,opt}];
	if(lgn==0)return cost_first;
	if(!opt){
		bool fir=1;
		auto calc=[&](LL k)->LL{
			if(!k)return 0;
			if(fir){
				fir=0;
				return cost_first+cost*(k-1);
			}else{
				return cost*k;
			}
		};
		int x=n[0];
		LL cur1=1e18;
		rep(i,0,9){
			if(s[0][(x+i)%10]!=s[0][(x+i+1)%10]){
				cur1=calc(i+1);
				break;
			}
		}
		fir=1;
		LL cur=0;
		x=n[0];
		while(x<9){
			++x;
			cur+=calc(1);
		}
		LL now=calc(1);
		return mp[{lgn,cost,cost_first,opt}]=min(cur1,cur+sol(n+1,s+1,lgn-1,cost*10,now,0));
	}
	vector<int>v;
	rep(j,0,9)if(j!=n[0]&&s[0][j]==s[0][(int)n[0]])v.pb(j);
	if(v.empty())return 0;
	LL res=0;
	rep(_,0,SZ(v)-1){
		auto deal=[&]()->LL{
			bool fir=1;
			auto calc=[&](LL k)->LL{
				if(!k)return 0;
				if(fir){
					fir=0;
					return cost_first+cost*(k-1);
				}else{
					return cost*k;
				}
			};
			LL w=1e18;
			{
				int x=n[0],y=v[_];
				rep(i,0,9){
					if(s[0][(x+i)%10]!=s[0][(y+i)%10]){
						w=i;
						break;
					}
				}
			}
			fir=1;
			int x=n[0],y=v[_];
			LL cur=0;
			while(x<9&&y<9){
				++x,++y;
				cur+=calc(1);
				if(s[0][x]!=s[0][y])return cur;
			}
			LL now=calc(1);
			fir=1;
			return min(cur+sol(n+1,s+1,lgn-1,cost*10,now,0),w<1e18?calc(w):w);
		};
		res=max(res,deal());
	}
	return mp[{lgn,cost,cost_first,opt}]=res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,18)pw[i]=pw[i-1]*10;
	scanf("%d",&T);
	while(T--){
		mp.clear();
		scanf("%d",&lgn);
		scanf("%s",n);
		rep(i,0,lgn-1)n[i]-='0';
		reverse(n,n+lgn);
		rep(i,0,lgn-1){
			scanf("%s",s[i]);
		}
		reverse(s,s+lgn);
		rep(i,0,lgn-1){
			val[i+1]=val[i]+n[i]*pw[i];
		}
		LL ans=0;
		rep(i,0,lgn-1){
			ans=max(ans,sol(n+i,s+i,lgn-i,pw[i],pw[i]-val[i],1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}