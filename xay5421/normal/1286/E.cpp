#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
using namespace std;
typedef long long LL;
const int N=600005,MASK=(1<<30)-1;
const LL P=1e18;
int n,w[N],nxt[N],anc[N];
int ans26,ansM;
char s[N];
pair<LL,LL>ans;
map<int,int>mp;
void ad(LL x){
	(ans26+=x%26)%=26;
	(ansM+=x&MASK)&=MASK;
	if((ans.X+=x)>=P){
		ans.X-=P;
		++ans.Y;
	}
}
void out(){
	if(ans.Y)printf("%lld%018lld\n",ans.Y,ans.X);
	else printf("%lld\n",ans.X);
}
vector<int>st;
void ps(int x){
	while(SZ(st)&&w[x]<=w[st.back()])st.pop_back();
	st.PB(x);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	while(!islower(s[1]=getchar()));
	scanf("%d",&w[1]);
	int j=0;
	st.PB(1);
	ad(w[1]);
	out();
	LL sum=0;
	rep(i,2,n){
		while(!islower(s[i]=getchar()));
		s[i]=(s[i]-'a'+ans26)%26+'a';
		scanf("%d",&w[i]);
		w[i]^=ansM;
		while(j&&s[j+1]!=s[i])j=nxt[j];
		if(s[j+1]==s[i])++j;
		nxt[i]=j;
		if(s[i]==s[nxt[i-1]+1]){
			anc[i]=anc[nxt[i-1]+1];
		}else{
			anc[i]=nxt[i-1]+1;
		}
		for(int k=i;k>1;){
			if(s[k]==s[i]){
				k=anc[k];
			}else{
				int tem=w[*lower_bound(st.begin(),st.end(),i-k+1)];
				sum-=tem;
				--mp[tem];
				if(mp[tem]==0)mp.erase(tem);
				k=nxt[k-1]+1;
			}
		}
		ps(i);
		if(s[i]==s[1]){
			sum+=w[i];
			++mp[w[i]];
		}
		int tt=0;
		for(auto it=mp.lower_bound(w[i]);it!=mp.end();){
			sum-=1LL*(it->X-w[i])*it->Y;
			tt+=it->Y;
			mp.erase(it++);
		}
		mp[w[i]]+=tt;
		ad(w[st[0]]+sum);
		out();
	}
	return 0;
}