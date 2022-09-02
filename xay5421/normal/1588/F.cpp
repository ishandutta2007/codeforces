// author: xay5421
// created: Sun Nov 14 15:37:55 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,B=500;
int n,Q,p[N],q[N],cyc[N],len,bel[N],big[N],cnt;
bool is[N],vis[N],hav[N];
LL a[N],sum[N],tg[N];
vector<int>vec[N];
tuple<int,int,int>qs[N];
int calc(vector<int>&v,int l,int r){
	return upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
}
void sol(int time_l,int time_r){
	//D("! %d %d\n",time_l,time_r);
	fill(vis+1,vis+1+n,0);
	fill(q+1,q+1+n,0);
	fill(is+1,is+1+n,0);
	fill(hav+1,hav+1+n,0);
	rep(_,time_l,time_r){
		int x,y,z;
		tie(x,y,z)=qs[_];
		if(x==3){
			is[p[y]]=is[p[z]]=1;
		}
		if(x==2){
			hav[y]=1;
		}
	}
	rep(i,1,n)if(!vis[i]){
		int x=i;
		len=0;
		int ok=0;
		while(!vis[x]){
			vis[x]=1;
			cyc[++len]=x;
			ok|=hav[x];
			x=p[x];
		}
		int lst=0;
		per(j,len,1){
			if(is[cyc[j]]){lst=cyc[j];break;}
		}
		if(!lst){
			if(ok){
				is[cyc[1]]=1;
				lst=cyc[1];
			}else{
				rep(j,1,len)bel[cyc[j]]=0;
				continue;
			}
		}
		rep(j,1,len){
			if(is[cyc[j]]){
				q[lst]=cyc[j];
				lst=cyc[j];
			}
			bel[cyc[j]]=lst;
		}
	}
	cnt=0;
	rep(i,1,n){
		if(is[i]){
			big[++cnt]=i,tg[i]=0;
		}
	}
	//D("cnt=%d\n",cnt);
	rep(i,1,n){
		vec[i].clear();
		//vec[i].shrink_to_fit();
	}
	rep(i,1,n){
		if(bel[i])vec[bel[i]].pb(i);
	}
	rep(_,time_l,time_r){
		int x,y,z;
		tie(x,y,z)=qs[_];
		if(x==1){
			LL ans=sum[z]-sum[y-1];
			rep(i,1,cnt){
				ans+=1LL*tg[big[i]]*calc(vec[big[i]],y,z);
			}
			pt(ans,'\n');
		}else if(x==2){
			int start=bel[y];
			int cur=start;
			do{
				tg[cur]+=z;
				cur=q[cur];
			}while(cur!=start);
		}else if(x==3){
			swap(q[bel[y]],q[bel[z]]);
		}
	}
	rep(i,1,n){
		a[i]+=tg[bel[i]];
		sum[i]=sum[i-1]+a[i];
	}
	rep(_,time_l,time_r){
		int x,y,z;
		tie(x,y,z)=qs[_];
		if(x==3){
			swap(p[y],p[z]);
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(a[i]),sum[i]=sum[i-1]+a[i];
	rep(i,1,n)rd(p[i]);
	rd(Q);
	rep(_,1,Q){
		rd(get<0>(qs[_]));
		rd(get<1>(qs[_]));
		rd(get<2>(qs[_]));
	}
	for(int l=1,r;l<=Q;l=r+1){
		r=min(Q,l+B-1);
		sol(l,r);
	}
	return 0;
}