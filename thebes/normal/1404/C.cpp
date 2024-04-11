#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 3e5+5;
int N, Q, i, j, x, y, arr[MN], ans[MN], lz[4*MN], st2[4*MN]; pii st[4*MN];
struct qur{int x, y, id;}q[MN];

void build(int i,int s,int e){
	if(s^e){
		build(2*i,s,(s+e)/2);
		build(2*i+1,(s+e)/2+1,e);
		st[i].F=min(st[2*i].F,st[2*i+1].F);
		st[i].S=(st[2*i].F<st[2*i+1].F)?st[2*i].S:st[2*i+1].S;
	}
	else st[i]={1<<30,s};
}

inline void upd_lz(int i,int s,int e){
	if(lz[i]){
		st[i].F += lz[i];
		if(s^e) lz[2*i]+=lz[i], lz[2*i+1]+=lz[i];
		lz[i] = 0;
	}
}

void upd(int i,int s,int e,int ss,int se){
	upd_lz(i,s,e);
	if(s>=ss&&e<=se) lz[i]--, upd_lz(i,s,e);
	else{
		if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se), upd_lz(2*i,s,(s+e)/2);
		else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se), upd_lz(2*i+1,(s+e)/2+1,e);
		else upd(2*i,s,(s+e)/2,ss,se), upd(2*i+1,(s+e)/2+1,e,ss,se);
		st[i].F=min(st[2*i].F,st[2*i+1].F);
		st[i].S=(st[2*i].F<st[2*i+1].F)?st[2*i].S:st[2*i+1].S;
	}
}

void upd2(int i,int s,int e,int ind,int val){
	upd_lz(i,s,e);
	if(s^e){
		if((s+e)/2<ind) upd2(2*i+1,(s+e)/2+1,e,ind,val), upd_lz(2*i,s,(s+e)/2);
		else upd2(2*i,s,(s+e)/2,ind,val), upd_lz(2*i+1,(s+e)/2+1,e);
		st[i].F=min(st[2*i].F,st[2*i+1].F);
		st[i].S=(st[2*i].F<st[2*i+1].F)?st[2*i].S:st[2*i+1].S;
	}
	else st[i] = {val, s};
}

void upd3(int i,int s,int e,int ind,int val){
	if(s^e){
		if((s+e)/2<ind) upd3(2*i+1,(s+e)/2+1,e,ind,val);
		else upd3(2*i,s,(s+e)/2,ind,val);
		st2[i] = st2[2*i] + st2[2*i+1];
	}
	else st2[i] = val;
}

int qu(int i,int s,int e,int ss,int se){
	if(s>=ss&&e<=se) return st2[i];
	else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
	else return qu(2*i,s,(s+e)/2,ss,se)+qu(2*i+1,(s+e)/2+1,e,ss,se);
}

int main(){
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=Q;i++){
		scanf("%d%d",&q[i].x,&q[i].y);
		q[i].x++; q[i].y = N-q[i].y;
		q[i].id = i;
	}
	sort(q+1,q+Q+1,[](qur i,qur j){return i.x>j.x;});
	int cur = N;
	build(1,1,N);
	for(i=1;i<=Q;i++){
		while(cur>=q[i].x){
			int val = 1<<30;
			if(arr[cur]<=cur) val = cur-arr[cur];
			upd2(1,1,N,cur,val);
			while(st[1].F<=0){
				int idx = st[1].S;
				upd2(1,1,N,idx,1<<30);
				upd(1,1,N,idx,N);
				upd3(1,1,N,idx,1);
			}
			cur--;
		}
		ans[q[i].id] = qu(1,1,N,q[i].x,q[i].y);
	}
	for(i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
	return 0;
}