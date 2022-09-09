#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=100050;
const ldb PI=acos(-1);
struct pt{ldb x,y;pt(){}pt(ldb a,ldb b):x(a),y(b){}}pts[N];
ldb abs(pt p){return sqrt(p.x*p.x+p.y*p.y);}
void fix(ldb&x){
	while(x>PI)x-=2*PI;
	while(x<=-PI)x+=2*PI;
}
pair<ldb,ldb> Make(pt p,ldb r){
	ldb dist=abs(p);
	ldb phi=acos(r/dist);
	ldb alpha=atan2(p.y,p.x);
	ldb L=alpha+phi;fix(L);
	ldb R=alpha-phi;fix(R);
	if(L>R)swap(L,R);
	return {L,R};
}
const int M=80*N;
int root[N*2],ls[M],rs[M],tsz,sum[M];
void Set(int p,int&c,int ss,int se,int qi){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+1;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p,int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return sum[c]-sum[p];
	int mid=ss+se>>1;
	return Get(ls[p],ls[c],ss,mid,qs,qe)+Get(rs[p],rs[c],mid+1,se,qs,qe);
}
void cl(){for(int i=1;i<=tsz;i++)ls[i]=rs[i]=sum[i]=0;tsz=0;}
int n;ll k;
pair<ldb,ldb> ang[N];
bool Check(ldb r){
	vector<pair<ldb,int>> all;
	ll cnt=0;
	int lef=n;
	for(int i=1;i<=n;i++){
		ldb dist=abs(pts[i]);
		if(dist<=r){
			cnt+=lef-1;
			lef--;
		}else{
			ang[i]=Make(pts[i],r);
			all.pb({ang[i].first,-i});
			all.pb({ang[i].second,i});
		}
	}
	sort(all.begin(),all.end());
	cl();
	map<int,int> idx;
	for(int i=0;i<all.size();i++){
		int j=all[i].second;
		root[i+1]=root[i];
		//printf("%i ",j);
		if(j>0){
			Set(root[i+1],root[i+1],1,all.size(),idx[j]);
			cnt+=Get(root[idx[j]],root[i+1],1,all.size(),idx[j]+1,i);
			cnt+=Get(root[0],root[idx[j]],1,all.size(),1,idx[j]-1);
		}else{
			idx[-j]=i+1;
		}
	}
	//printf("%.6f %i\n",r,cnt);
	return cnt>=k;
}
int main(){
	rd(n,k);
	for(int i=1;i<=n;i++){
		int x,y;rd(x,y);
		pts[i]=pt(x,y);
	}
	ldb top=1e5,bot=0;
	while(top-bot>1e-7){
		ldb mid=(top+bot)/2;
		if(Check(mid))top=mid;
		else bot=mid;
	}
	printf("%.12f\n",(top+bot)/2);
	return 0;
}