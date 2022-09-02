// author: xay5421
// created: Thu Dec 31 07:45:50 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7,bs=31;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=2000005;
int n,m,Q,pw[N],pw2[N];
string s[30];
vector<int>h[30],ha;
string t;
int get(const vector<int>&h,int l,int r){
	return su(h[l],mu(h[r+1],pw[r-l+1]));
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=pw2[0]=1;
	rep(i,1,N-1)pw[i]=mu(pw[i-1],bs),pw2[i]=ad(pw2[i-1],pw2[i-1]);
	scanf("%d%d",&n,&Q);
	cin>>s[0];
	cin>>t;
	m=SZ(t);
	rep(i,0,SZ(t)-1){
		s[i+1]=s[i]+t[i]+s[i];
		if(SZ(s[i+1])>1e6){
			m=i+1;
			break;
		}
	}
	rep(i,0,m){
		h[i].assign(SZ(s[i])+1,0);
		per(j,SZ(s[i])-1,0)h[i][j]=ad(mu(h[i][j+1],bs),s[i][j]-'a'+1);
	}
	t=" "+t;
	vector<array<int,26> >pre(SZ(t));
	rep(i,1,SZ(t)-1){
		//D("i=%d\n",i);
		pre[i]=pre[i-1];
		if(i>m)uad(pre[i][t[i]-'a'],po(pw2[i],P-2));
	}
	const int sz=SZ(s[m]);
	rep(_,1,Q){
		int id;
		string str;
		scanf("%d",&id);
		cin>>str;
		ha.assign(SZ(str)+1,0);
		per(j,SZ(str)-1,0)ha[j]=ad(mu(ha[j+1],bs),str[j]-'a'+1);
		int ans=0;
		rep(i,0,id){
			if(i>m)break;
			int mid=SZ(s[i])/2;
			int cnt=0;
			if(i==0){
				rep(l,0,SZ(s[0])-1){
					int r=l+SZ(str)-1;
					if(r>=SZ(s[0]))break;
					if(get(h[0],l,r)==ha[0])++cnt;
				}
			}else{
				rep(j,0,SZ(str)-1){
					int l=mid-j;
					if(l<0)break;
					int r=mid-j+SZ(str)-1;
					if(r>=SZ(s[i]))continue;
					if(get(h[i],l,r)==ha[0])++cnt;
				}
			}
			uad(ans,mu(pw2[id-i],cnt));
		}
		if(id>m){
			int res=0;
			auto ok1=[&](int x)->int{
				if(x<0)return 1;
				return get(ha,0,x)==get(h[m],sz-1-x,sz-1);
			};
			auto ok2=[&](int x)->int{
				if(x>=SZ(str))return 1;
				return get(ha,x,SZ(str)-1)==get(h[m],0,SZ(str)-1-x);
			};
			rep(i,0,SZ(str)-1){
				if(ok1(i-1)&&ok2(i+1)){
					uad(res,pre[id][str[i]-'a']);
				}
			}
			uad(ans,mu(res,pw2[id]));
		}
		printf("%d\n",ans);
	}
	return 0;
}