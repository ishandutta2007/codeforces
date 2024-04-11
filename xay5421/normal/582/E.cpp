#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=1e9+7;
int n,ind,f[505][(1<<16)+5],g[(1<<16)+5],h[(1<<16)+5];char s[505];
void addx(int&k1,int k2){(k1+=k2)>=P&&(k1-=P);}
void subx(int&k1,int k2){(k1-=k2)<0&&(k1+=P);}
void fwt_and(int*a,int t){
	void (*opx)(int&k1,int k2)=(t==1?addx:subx);
	for(int i=1;i<(1<<16);i<<=1)for(int j=0;j<(1<<16);j+=i<<1)for(int k=0;k<i;++k){
		opx(a[j+k],a[i+j+k]);
	}
}
void fwt_or(int*a,int t){
	void (*opx)(int&k1,int k2)=(t==1?addx:subx);
	for(int i=1;i<(1<<16);i<<=1)for(int j=0;j<(1<<16);j+=i<<1)for(int k=0;k<i;++k){
		opx(a[i+j+k],a[j+k]);
	}
}
int dfs(int l,int r){
//	cerr<<"dfs "<<l<<" "<<r<<endl;
	int k1=++ind;
	if(l==r){
		for(int i=0;i<4;++i){
			if(s[l]=='?'||s[l]=='A'+i){
				int cur=0;
				for(int j=0;j<(1<<4);++j)if(j>>i&1)cur|=1<<j;
				f[k1][cur]=1;
			}
			if(s[l]=='?'||s[l]=='a'+i){
				int cur=0;
				for(int j=0;j<(1<<4);++j)if(~j>>i&1)cur|=1<<j;
				f[k1][cur]=1;
			}
		}
		return k1;
	}
	int cur=0;
	for(int mid=l;mid<=r;++mid){
		if(s[mid]=='(')++cur;
		if(s[mid]==')')--cur;
		if(cur==0&&s[mid]!=')'){
			int lc=dfs(l+1,mid-2);
			int rc=dfs(mid+2,r-1);
			if(s[mid]!='|'){
				memcpy(g,f[lc],sizeof(g));
				memcpy(h,f[rc],sizeof(h));
				fwt_and(g,1),fwt_and(h,1);
				for(int j=0;j<(1<<16);++j)g[j]=1LL*g[j]*h[j]%P;
				fwt_and(g,-1);
				for(int j=0;j<(1<<16);++j)addx(f[k1][j],g[j]);
			}
			if(s[mid]!='&'){
				memcpy(g,f[lc],sizeof(g));
				memcpy(h,f[rc],sizeof(h));
				fwt_or(g,1),fwt_or(h,1);
				for(int j=0;j<(1<<16);++j)g[j]=1LL*g[j]*h[j]%P;
				fwt_or(g,-1);
				for(int j=0;j<(1<<16);++j)addx(f[k1][j],g[j]);
			}
			return k1;
		}
	}
	assert(0);
}
int main(){
	scanf("%s",s+1);
	scanf("%d",&n);
	vector<int>a(n),b(n);
	for(int i=0;i<n;++i){
		for(int j=0;j<4;++j){
			int x;scanf("%d",&x);
			if(x)a[i]|=1<<j;
		}
		scanf("%d",&b[i]);
	}
	int rt=dfs(1,strlen(s+1));
	int ans=0;
	for(int i=0;i<1<<16;++i){
		bool flg=1;
		for(int j=0;j<n;++j)if((i>>a[j]&1)!=b[j])flg=0;
		if(flg){
			addx(ans,f[rt][i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}