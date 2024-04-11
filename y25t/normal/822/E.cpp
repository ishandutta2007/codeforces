#include<bits/stdc++.h>
#define N 200005
#define K 35

namespace SA{
	int n;
	char s[N];
	
	#define W 20
	int sa[N],rk[N],a[N],m,b[N],c[N];
	inline void bs(){
		for(int i=1;i<=m;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			c[rk[i]]++;
		for(int i=1;i<=m;i++)
			c[i]+=c[i-1];
		for(int i=n;i;i--)
			sa[c[rk[a[i]]]--]=a[i];
	}
	int h[N],st[N][W];
	inline void init(){
		rk[n+1]=0;
		for(int i=1;i<=n;i++)
			rk[i]=s[i],a[i]=i;
		m=300,bs();
		for(int k=1;k<n;k<<=1){
			int t=0;
			for(int i=1;i<=k;i++)
				a[++t]=n-i+1;
			for(int i=1;i<=n;i++) if(sa[i]>k)
				a[++t]=sa[i]-k;
			bs();
			m=0;
			for(int i=1;i<=n;i++){
				if(!i||rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]+k]!=rk[sa[i-1]+k])
					m++;
				a[sa[i]]=m;
			}
			for(int i=1;i<=n;i++)
				rk[i]=a[i];
		}
		for(int i=1,k=0;i<=n;i++){
			if(rk[i]==1)
				continue;
			if(k)
				k--;
			int j=sa[rk[i]-1];
			while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])
				k++;
			h[rk[i]]=k;
		}
		for(int i=1;i<=n;i++)
			st[i][0]=h[i];
		for(int j=1;j<W;j++) for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	inline int lcp(int i,int j){
		if(i==j)
			return n-i+1;
		if(i>n||j>n)
			return 0;
		i=rk[i],j=rk[j];
		if(i>j)
			std::swap(i,j);
		i++;
		int k=31-__builtin_clz(j-i+1);
		return std::min(st[i][k],st[j-(1<<k)+1][k]);
	}
};

int n,m,k;
char s[N],t[N];

int f[N][K];

int main(){
	scanf("%d%s%d%s%d",&n,s+1,&m,t+1,&k);
	for(int i=1;i<=n;i++)
		SA::s[++SA::n]=s[i];
	SA::s[++SA::n]='$';
	for(int i=1;i<=m;i++)
		SA::s[++SA::n]=t[i];
	SA::init();
	for(int i=0;i<n;i++) for(int j=0;j<=k;j++){
		f[i+1][j]=std::max(f[i+1][j],f[i][j]);
		int l=SA::lcp(i+1,n+1+f[i][j]+1);
		if(l&&j<k)
			f[i+l][j+1]=std::max(f[i+l][j+1],f[i][j]+l);
	}
	puts(f[n][k]==m?"YES":"NO");
}