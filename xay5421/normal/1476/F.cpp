#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=300005,K=20;
int T,n,a[N],f[N][K],dp[N];
tuple<int,int>trans[N];
char ans[N];
int ask(int l,int r){
	int x=__lg(r-l+1);
	return max(f[l][x],f[r-(1<<x)+1][x]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,0,n)dp[i]=0;
		rep(i,1,n)scanf("%d",&a[i]),f[i][0]=i+a[i];
		rep(j,1,K-1){
			rep(i,1,n-(1<<j)+1){
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		int max_dp=0;
		vector<pair<int,int> >v={{0,0}};
		rep(i,1,n){
			if(max_dp>=i){
				dp[i]=max(max_dp,i+a[i]);
				trans[i]={1,i-1};
			}
			{
				if(max_dp<i-a[i]-1){
				}else{
					auto it=lower_bound(v.begin(),v.end(),pair<int,int>{i-a[i]-1,-1});
					assert(it!=v.end());
					int pos;
					tie(ignore,pos)=*it;
					if(dp[i]<i-1){
						trans[i]={2,pos};
						dp[i]=max(dp[i],i-1);
					}
					if(pos+1<i){
						int tmp=ask(pos+1,i-1);
						if(dp[i]<tmp){
							trans[i]={2,pos};
							dp[i]=tmp;
						}
					}
				}
			}
			if(dp[i]>max_dp){
				v.eb(dp[i],i);
				max_dp=dp[i];
			}else{
			}
		}
		if(max_dp<n){
			puts("NO");
		}else{
			puts("YES");
			fill(ans+1,ans+1+n,'R');
			ans[n+1]=0;
			int cur;
			tie(ignore,cur)=v.back();
			while(cur){
				int opt,from;
				tie(opt,from)=trans[cur];
				if(opt==1){
					--cur;
				}else{
					ans[cur]='L';
					cur=from;
				}
			}
			puts(ans+1);
		}
	}
	return 0;
}