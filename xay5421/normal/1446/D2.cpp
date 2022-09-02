#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int n,a[N],cnt[N],sum[N];
vector<int>pos[N];
set<int>S;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),++cnt[a[i]],pos[a[i]].PB(i);
	int tt=0,mx=0;
	rep(i,1,n){
		if(cnt[i]>cnt[mx]){
			mx=i;
			tt=0;
		}
		if(cnt[i]==cnt[mx]){
			++tt;
		}
	}
	if(tt>1){
		printf("%d\n",n);
		return 0;
	}
	rep(i,1,n+1)sum[i]=sum[i-1]+(a[i]==mx),a[i]==mx&&(S.insert(i),0);
	int ans=0;
	rep(i,1,n)if(i!=mx&&SZ(pos[i])){
		vector<int>v;
		for(auto x:pos[i]){
			{
				auto it=S.lower_bound(x);
				if(it!=S.begin()){
					v.PB(*prev(it));
					S.erase(prev(it));
				}
				if(it!=S.end()){
					v.PB(*it);
					S.erase(*it);
				}
			}
			{
				auto it=S.lower_bound(x);
				if(it!=S.begin()){
					v.PB(*prev(it));
					S.erase(prev(it));
				}
				if(it!=S.end()){
					v.PB(*it);
					S.erase(*it);
				}
			}
		}
		vector<int>t(v);
		for(auto x:pos[i])v.PB(x);
		{
			auto it=S.lower_bound(*min_element(v.begin(),v.end()));
			if(it!=S.begin()){
				--it;
				v.PB(*it);
			}
			v.PB(0);
			it=S.upper_bound(*max_element(v.begin(),v.end()));
			if(it!=S.end()){
				v.PB(*it);
			}
			v.PB(n+1);
		}
		sort(v.begin(),v.end());
		map<int,int>fi;
		fi[sum[v[0]]]=v[0];
		int s=0;
		rep(j,1,SZ(v)-1){
			if(fi.count(sum[v[j]-1]+s)){
				ans=max(ans,v[j]-1-fi[sum[v[j]-1]+s]);
			}
			if(a[v[j]]==i)--s;
			if(!fi.count(sum[v[j]]+s))fi[sum[v[j]]+s]=v[j];
		}
		for(auto x:t)S.insert(x);
	}
	printf("%d\n",ans);
	return 0;
}