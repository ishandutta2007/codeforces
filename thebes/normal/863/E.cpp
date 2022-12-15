#include <bits/stdc++.h>
using namespace std;

const int MN = 200005;
struct pii{int l, r, id;}arr[MN]; int st[3*MN], N, mx, i, lo, hi, idx, r = -1;
bool cmp(pii i,pii j){return(i.l==j.l)?(i.r>j.r):(i.l<j.l);}

void build(int i, int s, int e){
	if(s != e){
		build(2*i,s,(s+e)/2); build(2*i+1,(s+e)/2+1,e);
		st[i] = max(st[2*i], st[2*i+1]);
	}
	else st[i] = arr[s].r;
}

int query(int i, int s, int e, int ss, int se){
	if(s >= ss && e <= se) return st[i];
	else if((s+e)/2 < ss) return query(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2 >= se) return query(2*i,s,(s+e)/2,ss,se);
	else return max(query(2*i,s,(s+e)/2,ss,se),query(2*i+1,(s+e)/2+1,e,ss,se));
}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d%d",&arr[i].l,&arr[i].r);
		arr[i].id = i;
	}
	sort(arr+1, arr+N+1, cmp);
	mx = arr[1].r; build(1, 1, N);
	for(i=2;i<=N;i++){
		if(mx >= arr[i].r) r = arr[i].id;
		else if(i != N){
			lo = i+1; hi = N; idx = -1;
			while(lo != hi){
				if(arr[(lo+hi)/2].l <= mx+1){
					idx = max(idx,(lo+hi)/2);
					lo = (lo+hi)/2+1;
				}
				else hi = (lo+hi)/2;
			}
			if(arr[(lo+hi)/2].l <= mx+1) 
				idx = max(idx,(lo+hi)/2);
			if(idx != -1){
				if(query(1,1,N,i+1,idx) >= arr[i].r) 
					r = arr[i].id;
			}
		}
		mx = max(mx, arr[i].r);
		if(r != -1) break;
	}
	printf("%d\n",r);
	return 0;
}