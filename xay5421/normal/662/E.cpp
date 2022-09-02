#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=5005,INF=0X3F3F3F3F;
const int score[]={0,500,1000,1500,2000,2500,3000};
int n,a[N],b[N],c[N],seq[N],seq_[N],len,len_,dp[95][95][95],ndp[95][95][95];
int get_opt(int k){
	rep(i,1,5){
		if(n<(k<<i)&&(k<<i)<=n*2)return i;
	}
	return 6;
}
int calc(int opt,int t,int hacked=0){
	if(t==0||hacked)return 0;
	return score[opt]*(250-abs(t));
}
int fun(int opt,int cnt,int can){
	int l=opt==6?0:(n>>opt)+1;
	int r=n>>(opt-1);
	if(r<l||cnt<l||cnt-can>r){
		return -1;
	}
	return min(can,cnt-l);
}
int main(){
	scanf("%d",&n);
	int cnta=0,cntb=0,cntc=0;
	int cana=0,canb=0,canc=0;
	rep(i,1,n){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		cnta+=!!a[i];
		cntb+=!!b[i];
		cntc+=!!c[i];
		if(i>1){
			cana+=a[i]<0;
			canb+=b[i]<0;
			canc+=c[i]<0;
			if(a[i]<0||b[i]<0||c[i]<0){
				seq[++len]=i;
			}else{
				seq_[++len_]=i;
			}
		}
	}
	if(cana+canb+canc>90)puts("1"),exit(0);
	//D("cnta=%d cana=%d\n",cnta,cana);
	//D("cntb=%d canb=%d\n",cntb,canb);
	//D("cntc=%d canc=%d\n",cntc,canc);
	int ans=INF;
	rep(x,1,6)rep(y,1,6)rep(z,1,6){
		int hacka=fun(x,cnta,cana);
		int hackb=fun(y,cntb,canb);
		int hackc=fun(z,cntc,canc);
		if(hacka<0||hackb<0||hackc<0)continue;
		assert(get_opt(cnta-hacka)==x);
		assert(get_opt(cntb-hackb)==y);
		assert(get_opt(cntc-hackc)==z);
		int my_score=calc(x,a[1])+calc(y,b[1])+calc(z,c[1])+(hacka+hackb+hackc)*250*100;
		int base=0;
		rep(_,1,len_){
			int i=seq_[_];
			base+=calc(x,a[i])+calc(y,b[i])+calc(z,c[i])>my_score;
		}
		rep(va,0,hacka)rep(vb,0,hackb)rep(vc,0,hackc){
			dp[va][vb][vc]=INF;
		}
		dp[0][0][0]=0;
		assert(len<=90);
		rep(_,1,len){
			rep(va,0,hacka)rep(vb,0,hackb)rep(vc,0,hackc){
				ndp[va][vb][vc]=INF;
			}
			int i=seq[_];
			rep(takea,0,a[i]<0)rep(takeb,0,b[i]<0)rep(takec,0,c[i]<0){
				rep(va,0,hacka)rep(vb,0,hackb)rep(vc,0,hackc){
					int now_score=calc(x,a[i],takea)+calc(y,b[i],takeb)+calc(z,c[i],takec);
					umin(ndp[va+takea][vb+takeb][vc+takec],dp[va][vb][vc]+(now_score>my_score));
				}
			}
			rep(va,0,hacka)rep(vb,0,hackb)rep(vc,0,hackc){
				dp[va][vb][vc]=ndp[va][vb][vc];
			}
		}
		//D("x=%d y=%d z=%d hacka=%d hackb=%d hackc=%d dp=%d my_score=%d base=%d\n",x,y,z,hacka,hackb,hackc,dp[hacka][hackb][hackc]+1,my_score,base);
		ans=min(ans,dp[hacka][hackb][hackc]+1+base);
	}
	printf("%d\n",ans);
	return 0;
}