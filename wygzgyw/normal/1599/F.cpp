#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int s[N][4],C[4][4],sum[4],inv[N],pw[4],pwd[4],a[N];
std::map<int,std::vector<int>> mp;
inline int calc(int n,int k){
	if(k==0)return n+1;
	if(k==1)return 1LL*n*(n+1)/2%mod;
	if(k==2)return 1LL*n*(n+1)*(n+n+1)/6%mod;
	if(k==3){
		int tmp=1LL*n*(n+1)/2%mod;
		return 1LL*tmp*tmp%mod;
	}
	assert(0);
}
int main(){
	inv[0]=inv[1]=1;for(int i=2;i<N;++i)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	for(int i=0;i<4;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]),mp[a[i]].pb(i);
	for(int i=1;i<=n;++i)for(int j=0,cur=1;j<4;++j)s[i][j]=s[i-1][j],add(s[i][j],cur),cur=1ULL*cur*a[i]%mod;
	int l,r,d;
	while(q--){
		read(l,r,d);int L=r-l;
		for(int i=1;i<=3;++i)sum[i]=(s[r][i]-s[l-1][i]+mod)%mod;
		int x=(sum[1]-1LL*calc(L,1)*d%mod+mod)*inv[r-l+1]%mod;
		if(mp.find(x)==mp.end()){puts("No");continue;}
		std::vector<int> &v=mp[x];auto pos=std::lower_bound(v.begin(),v.end(),l);
		if(pos!=v.end()&&*pos<=r){
			pw[0]=1,pw[1]=x,pw[2]=1LL*x*x%mod,pw[3]=1LL*pw[2]*x%mod;
			pwd[0]=1;for(int i=1;i<4;++i)pwd[i]=1LL*pwd[i-1]*d%mod;
			bool flag=1;
			for(int i=2;i<=3;++i){
				int S=0;for(int j=0;j<=i;++j)add(S,1LL*C[i][j]*pw[j]%mod*pwd[i-j]%mod*calc(L,i-j)%mod);
				if(S!=sum[i]){flag=0;break;}
			}
			if(flag)puts("Yes");
			else puts("No");
		}
		else puts("No");
	}
	return 0;
}