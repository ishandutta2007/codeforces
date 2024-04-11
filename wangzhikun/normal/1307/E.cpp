#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int n,m,s[5050];
vector<int> G[5050],V[5050];
int diff[5050];
int enl1[5050],enl2[5050],rhs[5050];
int cnt[5050] = {0},el1[5050],el2[5050],pe[5050],way = 0,peway = 0;

int ans1 = 0,ans2 = 0;

int main() {
	read(n,m);
	for(int i=1;i<=n;i++){
		read(s[i]);
		V[s[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int f,h;
		read(f,h);
		G[f].push_back(h);
	}
	for(int i=1;i<=n;i++){
		for(auto ca:G[i]){
			if(ca>V[i].size())continue;
			//cout<<i<<' '<<ca<<endl;
			for(auto cb:G[i]){
				if(cb>V[i].size())continue;
				if(ca == cb)continue;
				//debug(ca);debug(cb);
				if(ca+cb<=V[i].size()){
					diff[V[i][ca-1]]+=1;
					rhs[V[i][ca-1]]+=1;
					diff[V[i][V[i].size()-cb]]-=1;
				}
			}
			if(!el2[i])way+=1;
			el2[i]+=1;
			enl1[V[i][ca-1]] += 1;
			enl2[V[i][V[i].size()-ca]] += 1;
		}
	}
	ans1=way,ans2=0;
	int cans = 1;
	for(int j=1;j<=n;j++){
		if(add(el1[j],el2[j]))cans = mul(cans,add(el1[j],el2[j]));
	}
	ans2 = add(ans2,cans);
	for(int i=1;i<=n;i++){
		way-=(cnt[s[i]]!=0)*(1+((el1[s[i]]+el2[s[i]])==0));
		cnt[s[i]]+=diff[i];
		way+=(cnt[s[i]]!=0)*(1+((el1[s[i]]+el2[s[i]])==0));
		if(cnt[s[i]] == 0)way-=((el1[s[i]]+el2[s[i]])!=0);
		el1[s[i]]+=enl1[i];
		el2[s[i]]-=enl2[i];
		if(cnt[s[i]] == 0)way+=((el1[s[i]]+el2[s[i]])!=0);
		if(way<ans1)continue;
		if(way>ans1)ans1=way,ans2=0;
		int cans = 1;
		for(int j=1;j<=n;j++){
			if(j == s[i]){
				if(cnt[j])cans = mul(cans,rhs[i]);
				else cans = mul(cans,enl1[i]);
			}else{
				if(cnt[j])cans = mul(cans,cnt[j]);
				else if(add(el1[j],el2[j]))cans = mul(cans,add(el1[j],el2[j]));
			}
		}
		ans2 = add(ans2,cans);
		//cout<<i<<' '<<ans1<<' '<<ans2<<endl;
	}
	if(ans1 == 0)ans2 = 1;
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}