// author: xay5421
// created: Tue Oct 26 19:43:00 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=2005;
int T,n,K;
char s[N],t[N];
void deal(char*s,vector<pair<int,int> >&op){
	int cnt1=count(s+1,s+1+n,'1');
	if(cnt1<K||K==0)return;
	auto kth=[&](int k){
		int cur=0;
		rep(i,1,n)if(s[i]=='1'&&++cur==k)return i;
		return -1;
	};
	auto ps=[&](int l,int r){
		reverse(s+l,s+r+1);
		op.eb(l,r);
	};
	if(cnt1==K){
		ps(1,kth(K));
		int pos=kth(K);
		int diff=0;
		rep(i,1,pos){
			if(s[i]!=s[pos-i+1]){
				diff=s[i]<s[pos-i+1]?1:-1;
				break;
			}
		}
		if(diff<0){
			ps(1,pos);
		}
		return;
	}
	int tail=n;
	while(cnt1>K+1){
		ps(kth(cnt1-K+1),tail--);
		--cnt1;
	}
	rep(i,1,K-1){
		if(i&1){
			ps(kth(1),kth(K+1)-1);
		}else{
			ps(kth(1)+1,kth(K+1));
		}
	}
	rep(i,1,K/2+1){
		ps(1,kth(K));
		ps(2,kth(K+1));
	}
}
void sol(){
	scanf("%d%d%s%s",&n,&K,s+1,t+1);
	vector<pair<int,int> >ops,opt;
	deal(s,ops);
	deal(t,opt);
	if(strncmp(s+1,t+1,n)){
		puts("-1");
		return;
	}
	printf("%d\n",SZ(ops)+SZ(opt));
	for(auto x:ops)printf("%d %d\n",x.first,x.second);
	reverse(opt.begin(),opt.end());
	for(auto x:opt)printf("%d %d\n",x.first,x.second);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	/*if(T==531){
		rep(_,1,T){
			scanf("%d%d%s%s",&n,&K,s+1,t+1);
			if(_==190){
				printf("%d %d\n",n,K);
				puts(s+1),puts(t+1);
			}
		}
	}*/
	while(T--){
		sol();
	}
	return 0;
}