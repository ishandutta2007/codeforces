#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
struct node{
	long long lazy = 0 , currmin = (long long) 1e18  ;
	int  lopt = (int) 1e9 + 2;
} ;

struct event{
	int tp;
	int x , y ,c;
 
};
struct point{
	int x , y , c;
};
int n;
vector<point> pts;
node *st = new node[(1<<21)];
set<int> ccs;
map<int,int> cp;
map<int,int> rcp;
int cc = 0;
vector<event> sweep;

void propaga(int l , int r , int curr){
		if(st[curr].lazy != 0){
			st[curr].currmin += st[curr].lazy;
			if(l!=r){
				// left->lazy += lazy;
				st[2*curr].lazy += st[curr].lazy;
				st[2*curr +1].lazy += st[curr].lazy;
			}
			st[curr].lazy = 0;
			return ;
		}
		return ;
}

void set_vl(int x , long long vl ,int lopt, int l = 0 , int r = cc - 1 , int curr = 1){
	int mid = (l+r)/2;
	if(l == x && r == x){
		st[curr].currmin = vl , st[curr].lopt = lopt; 
		return ;
	}
	if(x <= mid){
		set_vl(x,vl,lopt,l,mid,2*curr);
	}
	if(x > mid){
		set_vl(x,vl,lopt,mid+1,r,2*curr+1);
	}
	st[curr].currmin = min(st[2*curr].currmin , st[2*curr +1].currmin);
	if(st[curr].currmin == st[2*curr].currmin){
		st[curr].lopt = st[2*curr].lopt;
	}
	else{
		st[curr].lopt = st[2*curr+1].lopt;
	}
	return ;
}

#define pii pair<long long , long long>
void update(int x , int y , long long vl , int l = 0 , int r = cc - 1 , int curr = 1){
	int mid = (l+r)/2;
	propaga(l,r,curr);
	if(l == x && r == y){
		st[curr].lazy += vl;
		propaga(l,r,curr);
		return;
	}
	if(y <= mid){
		update(x,y,vl,l,mid,2*curr);
	}
	else if(x > mid) update(x,y,vl,mid+1,r,2*curr+1);
	else{
		update(x,mid,vl,l,mid,2*curr);
		update(mid+1,y,vl,mid+1,r,2*curr+1);
	}
	propaga(l,r,curr);
	propaga(l,mid,2*curr);
	propaga(mid+1,r,2*curr+1);
	pii U = min(pii(st[2*curr].currmin , st[2*curr].lopt) , pii(st[2*curr+1].currmin , st[2*curr +1].lopt));
	st[curr].currmin  = U.first, st[curr].lopt = U.second;
	return ;
}
#define F first
#define S second
pii query(int x , int y , int l = 0 , int r = cc - 1 , int curr =1){
	int mid = (l+r)/2;
	propaga(l,r,curr);
	if(l == x && r == y){
		return pii(st[curr].currmin , st[curr].lopt); 
	}
	if(y <= mid){
		return query(x,y,l,mid,2*curr);
	}
	else if(x > mid){
		return query(x,y,mid+1,r,2*curr +1);
	}
	else{
		return min(query(x,mid,l,mid,2*curr) , query(mid+1,y,mid+1,r,2*curr+1));
	}
}

int32_t main(){
	scanf("%d" , &n);
	pts.resize(n);
	for(int i = 0 ; i < n; i ++){
		scanf("%d%d%d" , &pts[i].x , &pts[i].y , &pts[i].c);
		if(pts[i].x > pts[i].y) swap(pts[i].x , pts[i].y);
		ccs.insert(pts[i].x) , ccs.insert(pts[i].y);
	}
	for(auto w : ccs){
		cp[w] = cc++;
	}
	for(int i = 0 ; i < n;i ++){
		int A = pts[i].x , B = pts[i].y;
		pts[i].x = cp[pts[i].x];
		rcp[pts[i].x] = A;
		pts[i].y = cp[pts[i].y];
		rcp[pts[i].y] = B;
	}
	for(int i = 0 ; i < n; i ++){
		set_vl(pts[i].x , -rcp[pts[i].x] , rcp[pts[i].x]);
		sweep.push_back({0 , pts[i].y , pts[i].x , pts[i].c});
		sweep.push_back({1 , pts[i].y , pts[i].y , 0});
		sweep.push_back({1 , pts[i].x , pts[i].x , 0});
	}
	sort(sweep.begin() , sweep.end() , [&](event a , event b){
		if(a.x == b.x){
			return a.tp < b.tp;
		}
		return a.x < b.x;
	});
	long long int ans = 0;
	pii ba  = pii((int) 1e9 + 2 ,(int) 1e9 + 2) , bb = pii((int) 1e9 + 2 , (int) 1e9 + 2);
	for(auto w : sweep){
		if(w.tp == 0){
			update(0 , w.y , -w.c);
			// cout<<w.tp <<" " << w.x<<" " <<w.y <<" " << rcp[w.y] <<" " << w.c << endl;
		}
		else{
			pii rr = query(0 , w.x );
			long long cr = -rcp[w.x] - rr.F;
			if(cr > ans){
				ans = cr;
				bb = pii(rcp[w.x] , rcp[w.x]);
				ba = pii(rr.S , rr.S);
			}
			// cout<<w.tp<< " " << w.x <<" " << w.y <<" " <<  rcp[w.x] <<" " << rcp[w.y] <<" " << rr.first<<" " << rr.second << endl;
 		}
	}	
	printf("%lld\n" , ans);
	printf("%lld %lld %lld %lld\n" , ba.F , ba.S , bb.F , bb.S);
}