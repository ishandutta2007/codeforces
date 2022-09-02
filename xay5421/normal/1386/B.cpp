// author: xay5421
// created: Wed Apr 28 09:46:53 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const double PI=acos(-1),eps=1e-9;
const int N=100005;
int A,B,C,n,_,_a[N],_b[N],_c[N];
double _A,_B,_C;
template<typename T>
T gcd(T a,T b){
	if(!a)return b;
	while(a^=b^=a^=b%=a,a);
	return b;
}
template<typename T>
void init(T&a,T&b,T&c){
	T g=__gcd(abs(a),__gcd(abs(b),abs(c)));
	if(g)a/=g,b/=g,c/=g;
	//if(a<0)a=-a,b=-b,c=-c;
}
map<tuple<LL,LL,LL>,int>mp;
int ans1,ans2,ans3;
double calc(double a,double b,double c){
	{
		double t=a+b+c;
		a/=t,b/=t,c/=t;
		a-=_A,b-=_B,c-=_C;
	}
	return atan2(b,a);
}
int sgn(double x){return fabs(x)<eps?0:x<0?-1:1;}
struct cmp{
	bool operator()(double k1,double k2)const{
		return sgn(k1-k2)<0;
	}
};
multiset<double,cmp>S;
void ps(int a,int b,int c,int v){
	init(a,b,c);
	if(a==A&&b==B&&c==C){
		ans1+=v;
		return;
	}
	LL x=1LL*B*c-1LL*C*b,y=1LL*C*a-1LL*A*c,z=1LL*A*b-1LL*B*a;
	init(x,y,z);
	if(v==1){
		if(++mp[make_tuple(x,y,z)]==1&&mp[make_tuple(-x,-y,-z)]>0)++ans2;
	}else if(v==-1){
		if(--mp[make_tuple(x,y,z)]==0&&mp[make_tuple(-x,-y,-z)]>0)--ans2;
	}
	double ang=calc(a,b,c);
	if(v==1){
		S.insert(ang);
	}else{
		S.erase(S.find(ang));
	}
}
bool chk(){
	if(*--S.end()-*S.begin()<PI+eps)return 0;
	auto k1=S.lower_bound(0),k2=k1;
	if(k1==S.begin()||k1==S.end())return 0;
	--k2;
	if(*k1-*k2>PI+eps)return 0;
	return 1;
	/*for(auto it=S.begin();it!=S.end();++it){
		if(next(it)!=S.end()){
			double ang=*next(it)-*it;
			if(ang>PI+eps)return 0;
		}
	}
	double ang=PI*2-*--S.end()+*S.begin();
	if(ang>PI+eps)return 0;
	return 1;*/
}
void out(){
	if(ans1)puts("1");
	else if(ans2)puts("2");
	else{
		if(SZ(S)<3||!chk())puts("0");
		else puts("3");
	}
}
int main(){
	scanf("%d%d%d%d",&A,&B,&C,&n);
	{
		double t=A+B+C;
		_A=1.*A/t;
		_B=1.*B/t,_C=1.*C/t;
	}
	init(A,B,C);
	rep(i,1,n){
		int c;
		while(!isalpha(c=getchar()));
		if(c=='A'){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			_a[++_]=a,_b[_]=b,_c[_]=c;
			ps(a,b,c,1);
		}else{
			int x;
			scanf("%d",&x);
			ps(_a[x],_b[x],_c[x],-1);
		}
		out();
	}
	return 0;
}