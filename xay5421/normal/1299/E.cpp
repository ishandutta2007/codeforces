#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define SZ(x) ((int)(x).size())
using namespace std;
const int N=500005;
int fpow(int k1,int k2,int P){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
void exgcd(int a,int b,int&x,int&y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int ginv(int k1,int P){
	int x,y;
	exgcd(k1,P,x,y);
	return (x%P+P)%P;
}
#ifdef xay5421
int p[N];
//mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(20050403);
int qry(vector<int>v){
	int res=0;
	for(auto x:v){
		res+=p[x];
	}
	return res%SZ(v)==0;
}
#else
int qry(const vector<int>&v){
	printf("? %d ",SZ(v));
	for(const auto&x:v)printf("%d ",x);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
#endif
int n;
int num[N],pos[N],odd[N];
void sol1(int t){
	bool fir=1;
	int a=0,b=0;
	rep(i,1,n)if(!num[i]){
		vector<int>v;
		rep(j,1,n)if(!num[j]&&j!=i)v.PB(j);
		if(qry(v)){
			if(fir){
				a=i;
				fir=0;
			}else{
				b=i;
			}
		}
	}
	pos[num[a]=t]=a;
	pos[num[b]=n+1-t]=b;
}
void out(){
	if(num[1]>n/2){
		rep(i,1,n)num[i]=n+1-num[i];
	}
	printf("! ");
	rep(i,1,n)printf("%d ",num[i]);
	puts("");
	exit(0);
}
int ask(int i,int P){
	if(P==3){
		if(qry({pos[1],pos[2],i}))return 0;
		if(qry({pos[2],pos[3],i}))return 1;
		return 2;
	}
	if(P==5){
		if(qry({pos[1],pos[2],pos[3],pos[n],i}))return 4-n%5;
		if(qry({pos[1],pos[2],pos[3],pos[n-1],i}))return 4-(n-1)%5;
		if(qry({pos[1],pos[2],pos[3],pos[n-2],i}))return 4-(n-2)%5;
		if(qry({pos[1],pos[2],pos[3],pos[n-3],i}))return 4-(n-3)%5;
		return 4-(n-4)%5;
	}
	if(P==7){
		int res=-1;
		auto ask=[&](int a,int b,int c,int d,int e,int f)->bool{
			int t=qry({pos[a],pos[b],pos[c],pos[d],pos[e],pos[f],i});
			if(t){
				res=((-a-b-c-d-e-f)%7+7)%7;
				return 1;
			}else return 0;
		};
		if(ask(1,2,3,n-3,n-2,n-1))return res;
		if(ask(1,2,4,n-3,n-2,n-1))return res;
		if(ask(1,2,4,n-3,n-2,n))return res;
		if(ask(1,3,4,n-3,n-2,n))return res;
		if(ask(1,3,4,n-3,n-1,n))return res;
		if(ask(2,3,4,n-3,n-1,n))return res;
		return ((-2-3-4-(n-2)-(n-1)-n)%7+7)%7;
	}
	assert(P==8);
	int res=odd[i];
	if(odd[i]){
		if(qry({pos[2],pos[3],pos[4],i}))res+=2;
	}else{
		if(qry({pos[1],pos[2],pos[3],i}))res+=2;
	}
	vector<int>v{pos[4],pos[1],pos[2],pos[3],pos[n-3],pos[n-2],pos[n-1],pos[n]};
	v[res]=i;
	if(!res)res=4;
	if(qry(v)){
		res+=4;
	}
	return res%8;
}
int main(){
	scanf("%d",&n);
#ifdef xay5421
	rep(i,1,n)p[i]=i;
	shuffle(p+1,p+1+n,rng);
	D("p : ");
	rep(i,1,n)D("%d ",p[i]);
	D("\n");
#endif
	sol1(1);
	rep(i,1,n)if(!num[i]){
		if(qry({pos[1],i}))odd[i]=1;
	}
	rep(i,2,min(4,n/2)){
		sol1(i);
		if(odd[pos[i]]!=(i&1)){
			swap(num[pos[i]],num[pos[n+1-i]]);
			swap(pos[i],pos[n+1-i]);
		}
	}
	if(n>8){
		const int M=3*5*7*8;
		vector<int>key{3,5,7,8};
		vector<int>coef(4);
		rep(i,0,3)coef[i]=ginv(M/key[i],key[i])*(M/key[i]);
		rep(i,1,n)if(!num[i])rep(j,0,3){
#ifdef xay5421
			int tmp=ask(i,key[j]);
			D(">>> p[%d] mod %d = %d\n",i,key[j],tmp);
			if(tmp!=p[i]%key[j]&&tmp!=(n+1-p[i])%key[j]){
				D("233\n");
			}
#endif
			(num[i]+=1LL*ask(i,key[j])*coef[j]%M)%=M;
		}
	}
	out();
	return 0;
}