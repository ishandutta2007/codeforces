#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 1e5+5, MS = 450, mod = 1e9+7;
int N, Q, i, arr[MN], x, y, nxt, rt[MN], lst, pr[2*MN];
struct nd{int l, r, p;}st[15000000];
vi primes;
stack<pii> stk[2*MN];

int qpow(int b,int exp){
	if(exp<=0) return 1;
	else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
	else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

int build(int s,int e){
	int cur = ++nxt;
	if(s^e){
        st[cur].l = build(s,(s+e)/2);
        st[cur].r = build((s+e)/2+1,e);
	}
	st[cur].p = 1;
	return cur;
}

int upd(int i,int s,int e,int ind,int val){
	int cur = ++nxt;
	if(s^e){
		if((s+e)/2<ind){
			st[cur].l = st[i].l;
			st[cur].r = upd(st[i].r,(s+e)/2+1,e,ind,val);
		}
		else{
			st[cur].l = upd(st[i].l,s,(s+e)/2,ind,val);
			st[cur].r = st[i].r;
		}
		st[cur].p = 1LL*st[st[cur].l].p*st[st[cur].r].p%mod;
	}
	else st[cur].p = 1LL*st[i].p*val%mod;
	return cur;
}

int qu(int i,int s,int e,int ss,int se){
	if(s>=ss&&e<=se) return st[i].p;
	else if((s+e)/2<ss) return qu(st[i].r,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(st[i].l,s,(s+e)/2,ss,se);
	else return 1LL*qu(st[i].l,s,(s+e)/2,ss,se)*qu(st[i].r,(s+e)/2+1,e,ss,se)%mod;
}

map<int,int> mp;

inline void process(int i,int pp){
    int cnt = 0;
    while(arr[i]%pp==0){
        cnt ++;
        arr[i] /= pp;
    }
    int pre = 0;
    while(stk[pp].size()){
        if(stk[pp].top().F<=cnt){
            if(!mp.count(stk[pp].top().S)) mp[stk[pp].top().S] = 1;
            mp[stk[pp].top().S] = 1LL*mp[stk[pp].top().S]*qpow(qpow(pp,stk[pp].top().F-pre),mod-2)%mod;
            pre = stk[pp].top().F;
            stk[pp].pop();
        }
        else break;
    }
    if(stk[pp].size()){
        int preidx = stk[pp].top().S;
        if(!mp.count(preidx)) mp[preidx] = 1;
        mp[preidx] = 1LL*mp[preidx]*qpow(qpow(pp,cnt-pre),mod-2)%mod;
    }
    if(!mp.count(i)) mp[i]=1;
    mp[i] = 1LL*mp[i]*qpow(pp,cnt)%mod;
    stk[pp].push({cnt,i});
}

int main(){
	pr[1] = 1;
	for(i=1;i<2*MN;i++){
		if(pr[i]) continue;
		if(i<=MS) primes.push_back(i);
		for(int j=2*i;j<2*MN;j+=i)
			pr[j] = 1;
	}
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	rt[0] = build(1,N);
	int ccnt = 0;
	for(i=1;i<=N;i++){
		rt[i] = rt[i-1];
		mp.clear();
		for(int j=0;j<(int)primes.size();j++){
            if(arr[i]%primes[j]==0){
                process(i,primes[j]);
            }
		}
		if(arr[i]!=1) process(i,arr[i]);
		for(auto v : mp){
            rt[i] = upd(rt[i], 1, N, v.F, v.S);
		}
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&x,&y);
		x = (x+lst)%N+1;
		y = (y+lst)%N+1;
		if(x>y) swap(x,y);
		lst = qu(rt[y],1,N,x,y);
		printf("%d\n",lst);
	}
	return 0;
}