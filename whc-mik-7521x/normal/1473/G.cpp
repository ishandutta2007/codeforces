#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod=998244353,G=3,Gi=332748118,inv2=499122177;
template<class T,class Alloc>
vector<T,Alloc>operator*(vector<T,Alloc>v1,vector<T,Alloc>v2){
	vector<T,Alloc>res=v1;
	res.resize(max(v1.size(),v2.size()));
	for(int i=0;i<(int)v2.size();i++)res[i]=res[i]*v2[i]%mod;
	return res;
}
template<class T,class Alloc>
vector<T,Alloc>operator*(vector<T,Alloc>v1,long long v2){
	vector<T,Alloc>res=v1;
	for(int i=0;i<(int)v1.size();i++)res[i]=res[i]*v2%mod;
	return res;
}
template<class T,class Alloc>
vector<T,Alloc>operator-(vector<T,Alloc>v1,vector<T,Alloc>v2){
	vector<T,Alloc>res=v1;
	res.resize(max(v1.size(),v2.size()));
	for(int i=0;i<(int)v2.size();i++)res[i]=((res[i]-v2[i])+mod)%mod;
	return res;
}
template<class T,class Alloc>
vector<T,Alloc>operator+(vector<T,Alloc>v1,vector<T,Alloc>v2){
	vector<T,Alloc>res=v1;
	res.resize(max(v1.size(),v2.size()));
	for(int i=0;i<(int)v2.size();i++)res[i]=(res[i]+v2[i])%mod;
	return res;
}
template<class T>
class poly{
	public:
	T fp(T x,T y){
		T res=1;
		while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1; 
		return res;
	}
	vector<T>reve(vector<T>vec){
		reverse(vec.begin(),vec.end());
		return vec;
	}
	vector<T>rsz(vector<T>vec,int len){
		vec.resize(len);
		return vec;
	}
	void btf_trans(vector<T>&t,int len){
		vector<int>rev(len);
		for(int i=0;i<len;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(len>>1):0);
		for(int i=0;i<len;i++)if(i<rev[i])swap(t[i],t[rev[i]]);
	}
	vector<T>NTT(vector<T>c,int len,int md){
		btf_trans(c,len);
		for(int siz=2;siz<=len;siz<<=1){
			T un=fp(md==1?G:Gi,(mod-1)/siz);
			for(int o=0;o<len;o+=siz){
				T w=1;
				for(int k=o;k<o+(siz>>1);k++){
					T p=c[k],q=c[k+(siz>>1)]*w%mod;
					c[k]=(p+q)%mod;
					c[k+(siz>>1)]=(p-q+mod)%mod;
					w=w*un%mod;
				}
			}
		}
		T kk=fp(len,mod-2);
		if(md==-1)for(int i=0;i<len;i++)c[i]=c[i]*kk%mod;
		return c;
	}
	vector<T>mul(vector<T>v1,vector<T>v2){
		int len=1<<(int)(log2(v1.size()+v2.size())+1);
		v1.resize(len),v2.resize(len);
		return NTT(NTT(v1,len,1)*NTT(v2,len,1),len,-1);
	}
	vector<T>inv(vector<T>vec){
		if(vec.size()==1)return {fp(vec.back(),mod-2)};
		vector<T>now=inv(rsz(vec,(vec.size()+1)/2));
		return rsz(now*2-(mul(vec,mul(now,now))),vec.size());
	}
	vector<T>dev(vector<T>vec){
		vector<T>res;
		for(int i=1;i<(int)vec.size();i++)res.push_back(i*vec[i]%mod);
		return res;
	}
	vector<T>inv_dev(vector<T>vec){
		vector<T>res(1,0);
		for(int i=1;i<=(int)vec.size();i++)res.push_back(vec[i-1]*fp(i,mod-2)%mod);
		return res;
	}
	vector<T>ln(vector<T>vec){
		return rsz(inv_dev(mul(dev(vec),inv(vec))),vec.size());
	}
	vector<T>exp(vector<T>vec){
		if(vec.size()==1)return vector<T>{1};
		vector<T>res=rsz(exp(rsz(vec,(vec.size()+1)>>1)),vec.size());
		vector<T>lnres=vec-ln(res);lnres[0]++;
		return rsz(mul(res,lnres),vec.size());
	}
	pair<vector<T>,vector<T>>div(vector<T>F,vector<T>G){
		vector<T>res1=rsz(mul(reve(F),inv(rsz(reve(G),F.size()))),F.size()-G.size()+1);
		reverse(res1.begin(),res1.end());
		return {res1,rsz(F-mul(G,res1),G.size()-1)};
	}
	vector<T>sqrt(vector<T>vec){
		if(vec.size()==1)return vector<T>{1};
		vector<T>res=sqrt(rsz(vec,(vec.size()+1)>>1));
		return rsz((res+(mul(inv(rsz(res,vec.size())),vec))),vec.size())*inv2;
	}
	vector<T>pw(vector<T>vec,long long k){
		return rsz(exp(ln(vec)*k),vec.size());
	}
};
namespace Math{
	long long fac[N],inv[N];
	long long fp(long long x,long long y){
		long long res=1;
		while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
		return res;
	}
	void init(){
		fac[0]=inv[0]=1;
		for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=fp(fac[N-1],mod-2);
		for(int i=N-2;i>=1;i--){
			inv[i]=inv[i+1]*(i+1)%mod;
		}
	}
	long long C(long long x,long long y){
		if(x<0||y<0||x<y)return 0;
		return fac[x]*inv[y]%mod*inv[x-y]%mod;
	}
	long long A(long long x,long long y){
		return fac[x]*inv[x-y]%mod;
	}
};
using namespace Math;
poly<long long>ty;
int n,kk=1;
int main(){
	init();
	vector<long long>ans={1};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		vector<long long>now;
		for(int o=y-kk+1;o<kk+x;o++)now.push_back(C(x+y,o));
		ans=ty.mul(ans,now);
		for(int o=0;o<kk+x-y;o++)ans[o]=ans[o+kk-1];
		kk=kk+x-y;
		ans.resize(kk);
	}
	long long res=0;
	for(auto it:ans)(res+=it)%=mod;
	printf("%lld",res);
	return 0;
}