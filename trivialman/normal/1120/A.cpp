#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 5e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int m,k,n,s,x,tot;
int a[N],cnt[N],last[N];
bool keep[N];
set<int> S;
vector<int> g[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d%d%d",&m,&k,&n,&s);
	rep(i,1,m)scanf("%d",a+i);
	memset(cnt,0,sizeof cnt);
	rep(i,1,s){
		scanf("%d",&x);
		if(!cnt[x]) ++tot;
		cnt[x]++;
	}
	
	rep(i,1,m){
		int x = a[i];
		g[x].push_back(i);
		if(g[x].size()>=cnt[x]+1) last[i] = g[x][g[x].size()-cnt[x]-1];
		//cout<<x<<" "<<last[i]<<endl;
	}
	 
	rep(i,1,m){
		cnt[a[i]]--;
		S.insert(i);
		if(cnt[a[i]]==0) --tot;
		if(last[i]){
			S.erase(last[i]);
			cnt[a[i]] = 0;
		}
		//cout<<i<<" "<<tot<<" "<<*S.begin()<<endl;
		if(tot==0){
			int x = *S.begin();
			if( (x-1)/k + (m-i)/k + 1 >= n){
				printf("%d\n",m-k*n);
				memset(keep,false,sizeof keep);
				for(auto x:S) keep[x] = true;
				int l = (x-1)/k*k+1;
				//cout<<i<<" "<<l<<" "<<keep[l]<<endl;
				int sum=0;
				rep(j,l,i){
					if(!keep[j] && i-l+1-sum>k) ++sum;
					else keep[j] = true;
				}
				rrep(j,m,i+1)
					if(sum<m-k*n) ++sum;
					else keep[j] = true;
				rrep(j,l-1,1)
					if(sum<m-k*n) ++sum;
					else keep[j] = true;
				rep(j,1,m)if(!keep[j])printf("%d ",j);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}