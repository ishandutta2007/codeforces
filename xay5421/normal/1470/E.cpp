// author: xay5421
// created: Wed Nov 10 07:59:40 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=30005;
int T,n,C,Q,p[N];
LL dp[N][5];
void sol(){
	rd(n),rd(C),rd(Q);
	rep(i,1,n)rd(p[i]);
	rep(i,0,C)dp[n+1][i]=1; // dp[i][j]  i  j 
	per(i,n,1){
		rep(j,0,C){
			dp[i][j]=dp[i+1][j];
			rep(k,1,j){
				if(i+k<=n)dp[i][j]+=dp[i+k+1][j-k];
			}
		}
	}
	vector<deque<tuple<int,int,LL> > >seq(C+1,deque<tuple<int,int,LL> >{tuple<int,int,LL>{n+1,n+1,1}}); // seq[c] <=c
	per(i,n,1){
		rep(c,1,C){
			vector<tuple<int,int,LL> >v1,v2;
			rep(j,1,c){
				if(i+j<=n){
					if(p[i+j]<p[i]){
						v1.eb(i,i+j,dp[i+j+1][c-j]);
					}else{
						v2.eb(i,i+j,dp[i+j+1][c-j]);
					}
				}
			}
			sort(v1.begin(),v1.end(),[&](const auto&lhs,const auto&rhs){return p[get<1>(lhs)]<p[get<1>(rhs)];});
			sort(v2.begin(),v2.end(),[&](const auto&lhs,const auto&rhs){return p[get<1>(lhs)]<p[get<1>(rhs)];});
			per(i,SZ(v1)-1,0)seq[c].pf(v1[i]);
			rep(i,0,SZ(v2)-1)seq[c].pb(v2[i]);
		}
	}
	vector<vector<int> >ll(C+1,vector<int>(n+1,0)),rr(C+1,vector<int>(n+1,0));
	vector<vector<LL> >sum(C+1);
	rep(c,1,C){
		ll[c][1]=0,rr[c][1]=SZ(seq[c])-1;
		rep(i,2,n){
			ll[c][i]=ll[c][i-1];
			rr[c][i]=rr[c][i-1];
			while(ll[c][i]<SZ(seq[c])&&get<0>(seq[c][ll[c][i]])<i)++ll[c][i];
			while(rr[c][i]>=0&&get<0>(seq[c][rr[c][i]])<i)--rr[c][i];
		}
		sum[c].assign(SZ(seq[c])+1,0);
		per(i,SZ(seq[c])-1,0){
			sum[c][i]=sum[c][i+1]+get<2>(seq[c][i]);
		}
	}
	rep(_,1,Q){
		LL K;
		int pos;
		rd(pos),rd(K);
		if(K>dp[1][C]){puts("-1");continue;}
		int c=C,now=1;
		while(1){
			//D("_=%d c=%d now=%d\n",_,c,now);
			int l=ll[c][now],r=rr[c][now],res=l;
			if(c==0){
				printf("%d\n",p[pos]);
				break;
			}
			while(l<=r){
				int mid=(l+r)>>1;
				if(sum[c][ll[c][now]]-sum[c][mid+1]>=K){
					res=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			if(get<0>(seq[c][res])>pos){
				printf("%d\n",p[pos]);
				break;
			}
			if(get<1>(seq[c][res])>=pos){
				printf("%d\n",p[get<1>(seq[c][res])-pos+get<0>(seq[c][res])]);
				break;
			}
			K-=sum[c][ll[c][now]]-sum[c][res];
			now=get<1>(seq[c][res])+1;
			c-=get<1>(seq[c][res])-get<0>(seq[c][res]);
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		sol();
	}
	return 0;
}