#ifdef xay5421
#define NDEBUG
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define EB emplace_back
using namespace std;
const int N=100005,B=31,P=998244853,Q=1e9+7;
int n,pw[1000005];
vector<int>h[N],rk[N],f[N];
string s[N];
int get(const vector<int>&h,int l,int r){
	return(h[l]-1LL*h[r+1]*pw[r-l+1]%P+P)%P;
}
void fun(vector<int>&rk,const string&s){
	vector<int>st1,st2;
	for(int i=0,j;i<SZ(s);i=j){
		j=i+1;
		while(j<SZ(s)&&s[i]==s[j])++j;
		if(j==SZ(s)||s[j]<s[i]){
			rep(k,i,j-1)st1.EB(k);
		}else{
			rep(k,i,j-1)st2.EB(k);
		}
	}
	rep(i,0,SZ(st1)-1)rk.EB(st1[i]);
	rk.EB(SZ(s));
	per(i,SZ(st2)-1,0)rk.EB(st2[i]);
}
bool chk(const string&s1,const vector<int>&h1,int p1,const string&s2,const vector<int>&h2,int p2){
	int i1=0,i2=0;
	static pair<int,int>rg1[2],rg2[2];
	rg1[0]=make_pair(0,p1-1),rg1[1]=make_pair(p1+1,SZ(h1)-1-1);
	rg2[0]=make_pair(0,p2-1),rg2[1]=make_pair(p2+1,SZ(h2)-1-1);
	while(i1<2||i2<2){
		while(i1<2&&rg1[i1].fi>rg1[i1].se)++i1;
		while(i2<2&&rg2[i2].fi>rg2[i2].se)++i2;
		if(i1>=2)return 1;
		if(i2>=2)return 0;
		int len=min(rg1[i1].se-rg1[i1].fi+1,rg2[i2].se-rg2[i2].fi+1);
		if(get(h1,rg1[i1].fi,rg1[i1].fi+len-1)!=get(h2,rg2[i2].fi,rg2[i2].fi+len-1)){
			int l=1,r=len,res=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(get(h1,rg1[i1].fi,rg1[i1].fi+mid-1)==get(h2,rg2[i2].fi,rg2[i2].fi+mid-1)){
					l=mid+1,res=mid;
				}else r=mid-1;
			}
			return s1[rg1[i1].fi+res]<s2[rg2[i2].fi+res];
		}
		rg1[i1].fi+=len,rg2[i2].fi+=len;
	}
	return 1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,1000005-1)pw[i]=1LL*pw[i-1]*B%P;
	scanf("%d",&n);
	rep(i,0,n-1){
		cin>>s[i];
		h[i].assign(SZ(s[i])+1,0);
		for(int j=SZ(s[i])-1;j>=0;--j)h[i][j]=(1LL*h[i][j+1]*B+s[i][j]-'a'+1)%P;
	}
	//D("%d\n",chk(s[4],h[4],0,s[5],h[5],1));
	rep(i,0,n-1){
		int sz=SZ(s[i]);
		f[i].assign(sz+1,0);
		fun(rk[i],s[i]);
		//D(">>> %d\n",i);
		if(i==0){
			rep(j,0,sz)f[i][j]=1;
		}else{
			int k=0;
			rep(j,0,sz){
				//D("running %d\n",j);
				while(k<SZ(rk[i-1])&&chk(s[i-1],h[i-1],rk[i-1][k],s[i],h[i],rk[i][j]))++k;
				if(k)f[i][j]=f[i-1][k-1];
			}
		}
		rep(j,1,sz)(f[i][j]+=f[i][j-1])%=Q;
	}
	printf("%d\n",f[n-1][SZ(s[n-1])]);
	return 0;
}