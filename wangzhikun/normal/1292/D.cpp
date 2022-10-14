#include <bits/stdc++.h>
#define int long long
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int cc;
int n,cnt[5050];

int cntt(int x,int v){
	int cd = v,ans = 0;
	ans+=x/cd;
	while(cd*v<=x){
		cd*=v;
		ans+=x/cd;
	}
	return ans;
}

int isnp[5050],val[5050],circ[5050] = {0};
vector<int> P,pe[5050];

signed main() {
	for(int i=2;i<5050;i++){
		if(isnp[i])continue;
		P.push_back(i);
		for(int j=i+i;j<5050;j+=i)isnp[j] = 1;
	}
	read(n);
	for(int i=0;i<n;i++){
		read(cc);
		if(cc == 0)cc+=1;
		cnt[cc]+=1;
	}
	int csu = 0;
	for(int i=1;i<=5000;i++){
		for(int j=P.size()-1;j>=0;j--){
			int ct = P[j];
			int cc = cntt(i,ct);
			for(int k=0;k<cc;k++)pe[i].push_back(ct);
			val[i]+=cntt(i,ct);
		}
		csu+=pe[i].size();
	}
	ll ans = 0;
	int po = 0,lag = 0;
	while(1){
		map<int,int> poll;
		for(int j=1;j<=5000;j++){
			if(circ[j] || !cnt[j])continue;
			if(po>=pe[j].size()) continue;
			else poll[pe[j][po]]+=cnt[j];
		}
		int cid = 0,cmx = 0;
		for(auto ct:poll){
			if(ct.second>cmx){
				cmx = ct.second;
				cid = ct.first;
			}
		}
		if(cmx*2>n){
			for(int j=1;j<=5000;j++){
				if(circ[j])continue;
				if(po>=pe[j].size()){
					lag+=cnt[j];
					circ[j] = 1;
				}else{
					if(pe[j][po]!=cid){
						lag+=cnt[j];
						ans+=1ll*cnt[j]*(pe[j].size()-po);
						circ[j] = 1;
					}
				}
			}
			ans+=lag;
		}else{
			for(int j=1;j<=5000;j++){
				if(circ[j])continue;
				if(po<pe[j].size())ans+=1ll*cnt[j]*(pe[j].size()-po);
			}
			break;
		}
		po+=1;
	}
	cout<<ans<<endl;
	return 0;
}