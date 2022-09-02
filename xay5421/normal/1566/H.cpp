// author: xay5421
// created: Mon Sep 13 00:42:08 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1000005;
int c,n,f[N],res[N],ans[N];
int num[N],mind[N];
bool ban[N];
int p[N];
vector<int>vec[N];
void sieve(){
	ban[0]=ban[1]=1;
	rep(i,2,N-1){
		if(!ban[i])p[++*p]=i,mind[i]=*p;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			mind[i*p[j]]=j;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	scanf("%d%d",&c,&n);
	per(i,int(sqrt(c)),2){
		rep(j,1,c/i/i){
			num[i*i*j]=i;
		}
	}
	vector<int>v;
	vector<int>pos;
	rep(i,1,c){
		if(!num[i]){
			pos.push_back(i);
			f[i]=SZ(v);
			v.push_back(i);
		}
	}
	printf("%d\n",SZ(v));
	for(auto x:v)printf("%d ",x);
	puts("");
	fflush(stdout);
	rep(i,0,SZ(v)-1){
		scanf("%d",&res[i]);
	}
	for(auto i:pos){
		f[i]=res[f[i]];
	}
	int sum=f[1];
	for(auto i:pos)f[i]^=sum;
	for(auto i:pos){
		vector<int>d;
		{
			int x=i;
			while(x>1){
				d.push_back(p[mind[x]]);
				x/=p[mind[x]];
			}
		}
		rep(j,0,(1<<SZ(d))-1){
			int x=i;
			rep(k,0,SZ(d)-1)if(j>>k&1)x/=d[k];
			if(x!=i)f[i]^=f[x];
		}
	}
	f[1]=sum;
	per(i_,SZ(pos)-1,0){
		int i=pos[i_];
		for(int j=i+i;j<=c;j+=i){
			f[i]^=f[j];
		}
	}
	auto calc=[&](int x){
		int tmp=1;
		while(num[x]){
			int t=num[x];
			tmp*=t;
			while(x%t==0)x/=t;
		}
		return tmp*x;
	};
	rep(i,1,c){
		vec[calc(i)].push_back(i);
	}
	vector<int>bads;
	vector<vector<bitset<265> > >whens;
	vector<bitset<265> >cans;
	int tot=0;
	rep(i,1,c)if(!vec[i].empty()){
		array<pair<int,bitset<265> >,20>b;
		vector<pair<int,int> >sb;
		auto ins=[&](int x,bitset<265>y)->int{
			per(j,19,0)if(x>>j&1){
				if(!b[j].first){
					b[j]={x,y};
					return 1;
				}else{
					x^=b[j].first;
					y^=b[j].second;
				}
			}
			return 0;
		};
		rep(j,0,SZ(vec[i])-1){
			bitset<265>tmp;
			tmp.set(j);
			if(!ins(vec[i][j],tmp)){
				sb.emplace_back(vec[i][j],j);
			}
		}
		mt19937 rng(233);
		if(sb.empty()){
			int val=f[i];
			bitset<265>st;
			per(j,19,0)if(val>>j&1){
				val^=b[j].first;
				st^=b[j].second;
			}
			for(int j=st._Find_first();j<265;j=st._Find_next(j)){
				ans[vec[i][j]]=vec[i][j];
				--n;
			}
		}else{
			tot+=SZ(vec[i]);
			bads.push_back(i);
			vector<bitset<265> >when(SZ(vec[i])+1);
			bitset<265>can;
			rep(_,1,100){
				int val=f[i];
				bitset<265>st;
				rep(j,0,SZ(sb)-1){
					if(rng()&1){
						val^=sb[j].first;
						st.set(sb[j].second);
					}
				}
				per(j,19,0)if(val>>j&1){
					val^=b[j].first;
					st^=b[j].second;
				}
				when[st.count()]=st;
				can[st.count()]=1;
			}
			whens.push_back(when);
			cans.push_back(can);
			sb.clear();
		}
	}
	D("tot=%d\n",tot);
	bitset<40005>cur;
	cur.set(0);
	vector<bitset<40005> >dp(SZ(bads));
	rep(i,0,SZ(bads)-1){
		dp[i]=cur;
		bitset<40005>nex;
		for(int j=cans[i]._Find_first();j<265;j=cans[i]._Find_next(j)){
			nex|=cur<<j;
		}
		cur=nex;
	}
	assert(cur[n]);
	per(i,SZ(bads)-1,0){
		D("i=%d\n",i);
		int sz=-1;
		for(int j=cans[i]._Find_first();j<265;j=cans[i]._Find_next(j)){
			if(dp[i][n-j]){
				sz=j;
				break;
			}
		}
		assert(sz!=-1);
		for(int j=whens[i][sz]._Find_first();j<265;j=whens[i][sz]._Find_next(j)){
			ans[vec[bads[i]][j]]=vec[bads[i]][j];
		}
		n-=sz;
	}
	rep(i,1,c)if(ans[i]!=0)printf("%d ",i);
	puts("");
	fflush(stdout);
	return 0;
}