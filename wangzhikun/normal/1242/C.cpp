#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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

int k,cnt[20];
vector<int> num[20];
set<int> snum[20];
vector<pii> alnum;
ll fsum[20] = {0};

struct sol{
	int eans[20],ans[20],ansp[20];
};

int psol[35000],fr[35000];
sol asol[35000];

int eans[20],cans[20],cansp[20],uns[20];
ll msum[20];
bool fnd(ll qk,int lp){
	for(int cc = 0;cc<k;cc++){
		if(snum[cc].count(qk)){
			if(eans[cc])return 0;
			uns[cc] = 1;
			eans[cc] = 1;
			msum[cc]-=qk;
			cans[cc] = qk;
			cansp[cc] = lp;
			return 1;
		}
	}
	return 0;
}

signed main() {
	read(k);
	
	ll alsum = 0;
	for(int i=0;i<k;i++){
		read(cnt[i]);
		for(int j=0;j<cnt[i];j++){
			int cu;
			read(cu);
			fsum[i]+=cu;
			snum[i].insert(cu);
			num[i].push_back(cu);
		}
		alsum+=fsum[i];
		sort(num[i].begin(),num[i].end());
	}
	if(alsum%k!=0){
		cout<<"No"<<endl;
		return 0;
	}
	ll echrq = alsum/k;
	for(int tst = 0;tst<k;tst++){
		for(int i=0;i<cnt[tst];i++){
			int cb =0;
			memset(eans,0,sizeof(eans));
			memset(cans,0,sizeof(cans));
			memset(cansp,0,sizeof(cansp));
			memset(uns,0,sizeof(uns));
			memcpy(msum,fsum,sizeof(fsum));
			msum[tst] -= num[tst][i];
			//cout<<tst<<' '<<i<<endl;
			ll init = num[tst][i];
			uns[tst] = 1;
			while(1){
				int flg = 0;
				for(int j=0;j<k;j++){
					if(uns[j] && (eans[j] || j == tst)){
						//cout<<"CP "<<j<<' '<<echrq-msum[j]<<endl;
						bool cc = fnd(echrq-msum[j],j);
						if(!cc)goto nxt;
						if(echrq-msum[j] == init) uns[tst] = 0;
						msum[j] = echrq;
						uns[j] = 0;
						flg = 1;
					}
				}
				if(!flg)break;
			}
			//cout<<"FND"<<cb<<endl;
			memcpy(msum,fsum,sizeof(fsum));
			for(int j=0;j<k;j++){
				if(eans[j]){
					msum[j]-=cans[j];
					msum[cansp[j]]+=cans[j];
				}
			}
			for(int j=0;j<k;j++){
				if(eans[j] && msum[j]!=echrq){
					goto nxt;
				}
			}
			for(int j=0;j<k;j++)if(eans[j])cb|=(1<<j);
			//cout<<"FND"<<cb<<endl;
			psol[cb] = 1;
			fr[cb] = 0;
			memcpy(asol[cb].eans,eans,sizeof(eans));
			memcpy(asol[cb].ans,cans,sizeof(cans));
			memcpy(asol[cb].ansp,cansp,sizeof(cansp));
			nxt:;
		}
	}
	for(int i=0;i<1<<k;i++){
		if(psol[i] == 1)continue;
		for(int j=i;j;j = (j-1)&i){
			if(psol[j] == 1 && psol[i^j]){
				fr[i] = i^j;
				psol[i] = 2;
			}
		}
	}
	if(psol[(1<<k)-1]){
		cout<<"Yes"<<endl;
		int cc = (1<<k)-1;
		while(cc!=0){
			//cout<<cc<<' '<<fr[cc]<<endl;
			int cf = cc^fr[cc];
			for(int i=0;i<k;i++){
				if(asol[cf].eans[i]){
					cans[i] = asol[cf].ans[i];
					cansp[i] = asol[cf].ansp[i];
				}
			}
			cc = fr[cc];
		}
		for(int i=0;i<k;i++){
			cout<<cans[i]<<' '<<cansp[i]+1<<endl;
		}
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}