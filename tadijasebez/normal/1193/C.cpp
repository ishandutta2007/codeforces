//Idea from krijgertje's code
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}

const ldb eps=1e-9;
bool eq(ldb a,ldb b){return fabs(a-b)<eps;}

struct pt{ldb x,y;pt(){}pt(ldb a,ldb b):x(a),y(b){}};
pt operator+(pt a,pt b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
pt operator*(ldb b,pt a){return pt(a.x*b,a.y*b);}
pt operator/(pt a,ldb b){return pt(a.x/b,a.y/b);}
bool operator==(pt a,pt b){return eq(a.x,b.x)&&eq(a.y,b.y);}
ldb cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
ldb dot(pt a,pt b){return a.x*b.x+a.y*b.y;}
ldb sq(pt a){return dot(a,a);}
ldb abs(pt a){return sqrt(sq(a));}
ldb dist(pt a,pt b){return abs(a-b);}

struct ply{
	vector<pt> pts;int id;
	ply():id(0){}ply(vector<pt> ps):pts(ps),id(0){}
	void add(pt x){pts.pb(x);}
	pt&operator[](int i){return pts[i];}int sz(){return pts.size();}
	bool is_rec(){return pts.size()==4&&eq(pts[0].x,0)&&eq(pts[0].y,0)&&eq(pts[1].y,0)&&eq(pts[3].x,0)&&eq(pts[1].x,pts[2].x)&&eq(pts[2].y,pts[3].y);}
	bool is_sq(){return is_rec()&&eq(pts[2].x,pts[2].y);}
	bool is_tri(){return pts.size()==3;}
	void p(){printf("%i ",pts.size());for(auto p:pts)printf("%.10f %.10f ",p.x,p.y);printf("\n");}
	ldb area(){
		ldb ans=0;
		for(int i=0,j=pts.size()-1;i<pts.size();j=i,i++){
			ans+=cross(pts[i],pts[j]);
		}
		return fabs(ans)/2;
	}
};
ply operator+(ply a,pt b){for(pt&p:a.pts)p=p+b;return a;}
void rot(ply&a){pt tmp=a[0];a[0]=a[1];a[1]=a[2];a[2]=tmp;}
bool inside(pt a,pt b,pt c,pt d){return eq(ply({a,b,c}).area(),ply({a,b,d}).area()+ply({a,c,d}).area()+ply({b,c,d}).area());}

struct op{char typ;int shp;vector<int> fen;};
op sci(int shp,vector<int> fen){op ans;ans.typ='s';ans.shp=shp;ans.fen=fen;return ans;}
op tap(vector<int> fen,int shp){op ans;ans.typ='t';ans.shp=shp;ans.fen=fen;return ans;}
op mve(int src,int dst){op ans;ans.typ='m';ans.shp=src;ans.fen={dst};return ans;}

struct Solve{
	vector<ply> pls;
	vector<op> ops;
	int add(ply p){pls.pb(p);return pls.size()-1;}
	int tri_to_rec(int tid){
		ply tmp=pls[tid];
		int cnt=0;
		while(1){
			ldb a=dist(tmp[0],tmp[1]);
			ldb b=dist(tmp[1],tmp[2]);
			ldb c=dist(tmp[2],tmp[0]);
			if(b>a||c>a){rot(tmp);cnt++;continue;}
			ldb A=pls[tid].area();
			ldb h=(A*2)/a;
			ldb x=sqrt(c*c-h*h);
			int aid;
			if(cnt==0)aid=add(ply({pt(0,0),pt(a,0),pt(x,h)}));
			if(cnt==1)aid=add(ply({pt(x,h),pt(0,0),pt(a,0)}));
			if(cnt==2)aid=add(ply({pt(a,0),pt(x,h),pt(0,0)}));
			ops.pb(mve(tid,aid));
			pt l=(pt(0,0)+pt(x,h))/2,r=(pt(x,h)+pt(a,0))/2;
			int bid=add(ply({pt(0,0),pt(a,0),r,l}));
			int cid=add(ply({pt(x,h/2),pt(x,h),l}));
			int did=add(ply({pt(x,h/2),r,pt(x,h)}));
			ops.pb(sci(aid,{bid,cid,did}));
			int eid=add(ply({pt(0,h/2),pt(0,0),l}));
			ops.pb(mve(cid,eid));
			int fid=add(ply({pt(a,h/2),r,pt(a,0)}));
			ops.pb(mve(did,fid));
			int gid=add(ply({pt(0,0),pt(a,0),pt(a,h/2),pt(0,h/2)}));
			ops.pb(tap({bid,eid,fid},gid));
			return gid;
		}
	}
	int rsz_rec_h(int rid,ldb s){
		assert(pls[rid].is_rec());
		ldb h=pls[rid][2].y,w=pls[rid][2].x;
		if(eq(h,s))return rid;
		if(s>h*2){
			ply tmp=ply({pt(0,0),pt(w/2,0),pt(w/2,h),pt(0,h)});
			int aid=add(tmp);
			int bid=add(tmp+pt(w/2,0));
			ops.pb(sci(rid,{aid,bid}));
			int cid=add(tmp+pt(0,h));
			ops.pb(mve(bid,cid));
			int did=add(ply({pt(0,0),pt(w/2,0),pt(w/2,h*2),pt(0,h*2)}));
			ops.pb(tap({aid,cid},did));
			return rsz_rec_h(did,s);
		}else if(h>2*s){
			ply tmp=ply({pt(0,0),pt(w,0),pt(w,h/2),pt(0,h/2)});
			int aid=add(tmp);
			int bid=add(tmp+pt(0,h/2));
			ops.pb(sci(rid,{aid,bid}));
			int cid=add(tmp+pt(w,0));
			ops.pb(mve(bid,cid));
			int did=add(ply({pt(0,0),pt(w*2,0),pt(w*2,h/2),pt(0,h/2)}));
			ops.pb(tap({aid,cid},did));
			return rsz_rec_h(did,s);
		}else if(s>h){
			ldb t=h*w/s,x=s-h,y=w-t;
			int aid=add(ply({pt(0,0),pt(t,0),pt(t,x),pt(y,h),pt(0,h)}));
			int bid=add(ply({pt(t,0),pt(w,0),pt(t,x)}));
			int cid=add(ply({pt(w,0),pt(w,h),pt(y,h)}));
			ops.pb(sci(rid,{aid,bid,cid}));
			int did=add(ply({pt(0,h),pt(y,h),pt(0,s)}));
			ops.pb(mve(bid,did));
			int eid=add(ply({pt(t,x),pt(t,s),pt(0,s)}));
			ops.pb(mve(cid,eid));
			int sid=add(ply({pt(0,0),pt(t,0),pt(t,s),pt(0,s)}));
			ops.pb(tap({aid,did,eid},sid));
			return sid;
		}else{
			ldb t=h*w/s,x=h-s,y=t-w;
			int aid=add(ply({pt(0,0),pt(w,0),pt(w,x),pt(y,s),pt(0,s)}));
			int bid=add(ply({pt(0,s),pt(y,s),pt(0,h)}));
			int cid=add(ply({pt(w,x),pt(w,h),pt(0,h)}));
			ops.pb(sci(rid,{aid,bid,cid}));
			int did=add(ply({pt(w,0),pt(t,0),pt(w,x)}));
			ops.pb(mve(bid,did));
			int eid=add(ply({pt(t,0),pt(t,s),pt(y,s)}));
			ops.pb(mve(cid,eid));
			int sid=add(ply({pt(0,0),pt(t,0),pt(t,s),pt(0,s)}));
			ops.pb(tap({aid,did,eid},sid));
			return sid;
		}
	}
	int rec_to_sq(int rid){
		ldb s=sqrt(pls[rid][2].x*pls[rid][2].y);
		return rsz_rec_h(rid,s);
	}
	int tri_to_sq(int tid){return rec_to_sq(tri_to_rec(tid));}
	int mrg_sqs(int sid1,int sid2){
		ldb s1=pls[sid1][1].x,s2=pls[sid2][1].x,s=sqrt(s1*s1+s2*s2);
		int rid1=rsz_rec_h(sid1,s);
		int rid2=rsz_rec_h(sid2,s);
		ldb w1=pls[rid1][2].x;
		int aid=add(ply({pt(w1,0),pt(s,0),pt(s,s),pt(w1,s)}));
		ops.pb(mve(rid2,aid));
		int bid=add(ply({pt(0,0),pt(s,0),pt(s,s),pt(0,s)}));
		ops.pb(tap({rid1,aid},bid));
		return bid;
	}
	int ply_to_sq(int pid){
		ply tmp=pls[pid];
		vector<int> tri;
		while(tmp.sz()>=3){
			for(int i=0,l=tmp.sz()-1,r=1;i<tmp.sz();l=i,i++,r=r+1==tmp.sz()?0:r+1){
				if(cross(tmp[i]-tmp[l],tmp[r]-tmp[l])>0){
					bool ok=1;
					for(int j=0;j<tmp.sz();j++)if(j!=l&&j!=i&&j!=r)ok&=!inside(tmp[l],tmp[i],tmp[r],tmp[j]);
					if(!ok)continue;
					tri.pb(add(ply({tmp[l],tmp[i],tmp[r]})));
					tmp.pts.erase(tmp.pts.begin()+i);
				}
			}
		}
		ops.pb(sci(pid,tri));
		vector<int> sqs;
		for(int i:tri)sqs.pb(tri_to_sq(i));
		while(sqs.size()>1){
			int i=sqs.back();sqs.pop_back();
			sqs.back()=mrg_sqs(sqs.back(),i);
		}
		return sqs[0];
	}
	int to_sq(int pid){
		if(pls[pid].is_rec())return rec_to_sq(pid);
		if(pls[pid].is_tri())return tri_to_sq(pid);
		return ply_to_sq(pid);
	}
}A,B;
int solve(Solve&A){
	ply st;int n=ri();for(int i=1,x,y;i<=n;i++)rd(x,y),st.add(pt(x,y));
	int pid=A.add(st);
	return A.to_sq(pid);
}
int main(){
	int aid=solve(A);
	int bid=solve(B);
	vector<ply> pls;
	vector<op> ops;
	for(ply p:A.pls)pls.pb(p);
	for(ply p:B.pls)pls.pb(p);
	auto cng=[&](int&i){if(i==bid)i=aid;else i+=A.pls.size();};
	for(op o:A.ops)ops.pb(o);
	reverse(B.ops.begin(),B.ops.end());
	for(op&o:B.ops){
		cng(o.shp);
		for(int&i:o.fen)cng(i);
		if(o.typ=='s')o.typ='t';
		else if(o.typ=='t')o.typ='s';
		else swap(o.shp,o.fen[0]);
		ops.pb(o);
	}
	int cnt=0;
	for(op o:ops){
		if(o.typ=='s'){
			printf("scissors\n");
			printf("%i %i\n",pls[o.shp].id,o.fen.size());
			for(int i:o.fen){
				pls[i].id=++cnt;
				pls[i].p();
			}
		}else if(o.typ=='t'){
			printf("tape\n");
			printf("%i ",o.fen.size());
			for(int i:o.fen)printf("%i ",pls[i].id);
			printf("\n");
			for(int i:o.fen)pls[i].p();
			pls[o.shp].id=++cnt;
			pls[o.shp].p();
		}else{
			printf("tape\n");
			printf("1 %i\n",pls[o.shp].id);
			pls[o.fen[0]].p();
			pls[o.fen[0]].p();
			pls[o.fen[0]].id=++cnt;
		}
	}
	return 0;
}