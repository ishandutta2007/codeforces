#include<bits/stdc++.h>
#define X first
#define Y second
#define EB emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,m,lst[26],pre[N][26],nxt[N][26],sgl[N][26],sgr[N][26],sum[N];char s[N];
int sol(int l,int r){
	int num=0;
	rep(i,0,25){
		if(nxt[l-1][i]<=r){
			num|=1<<(sgr[l][i]^sgl[r][i]^sum[pre[r+1][i]]^sum[nxt[l-1][i]]);
		}
	}
	rep(i,0,26)if(~num>>i&1)return i;
	assert(0);
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%s%d",s+1,&m),n=strlen(s+1);
	rep(i,1,n)memcpy(pre[i],lst,sizeof(lst)),lst[s[i]-'a']=i;
	memcpy(pre[n+1],lst,sizeof(lst));
	fill(lst,lst+26,n+1);
	per(i,n,1)memcpy(nxt[i],lst,sizeof(lst)),lst[s[i]-'a']=i;
	memcpy(nxt[0],lst,sizeof(lst));
	rep(i,1,n){
		sum[i]=sum[pre[i][s[i]-'a']]^sgl[i-1][s[i]-'a'];
		vector<pair<int,int> >ned;
		rep(j,0,25)if(s[i]-'a'!=j&&pre[i][j])ned.EB(pre[i][j]+1,0);
		if(i!=n)rep(j,pre[i+1][s[i+1]-'a']+1,i)ned.EB(j,1);
		sort(ned.rbegin(),ned.rend());
		for(auto x:ned){
			int cur=sol(x.X,i);
			if(x.Y==1)sgr[x.X][s[i+1]-'a']=cur;
			else if(x.X-1)sgl[i][s[x.X-1]-'a']=cur;
		}
	}
	rep(i,1,m){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%s\n",sol(l,r)?"Alice":"Bob");
	}
	return 0;
}