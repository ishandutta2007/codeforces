#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 205

int n,m;
ll k;

std::vector<int> s;

struct node{
	ll cnt,len;
	std::vector<int> a,b;
	node(){
		cnt=0;
		a.assign(s.size()+1,0);
		b.assign(s.size()+1,0);
	}
};
node operator + (node x,node y){
	node res;
	res.cnt=std::min(inf,x.cnt+y.cnt);
	for(int i=1;i<s.size();i++)
		res.cnt=std::min(inf,res.cnt+x.b[i]*y.a[s.size()-i]);
	res.a=x.a,res.b=y.b;
	return res;
}

inline node sol(std::vector<int> &a){
	node res;
	for(int i=0;i+s.size()-1<a.size();i++){
		bool flg=1;
		for(int j=0;j<s.size();j++)
			if(a[i+j]!=s[j])
				flg=0;
		res.cnt+=flg;
	}
	for(int i=1;i<=s.size();i++){
		res.a[i]=1;
		for(int j=0;j<i;j++)
			if(a[j]!=s[s.size()-i+j])
				res.a[i]=0;
		res.b[i]=1;
		for(int j=0;j<i;j++)
			if(a[a.size()-i+j]!=s[j])
				res.b[i]=0;
	}
	return res;
}

node f[N];
std::vector<int> a[N];
inline ll cal(){
	for(int i=1;i<=n;i++)
		f[i]=node();
	int t;
	a[0].clear(),a[1].clear();
	a[0].push_back(0),a[1].push_back(1);
	for(t=2;t<=n&&a[t-2].size()<s.size();t++){
		a[t]=a[t-2];
		for(auto x:a[t-1])
			a[t].push_back(x);
	}
	t--;
	f[t-1]=sol(a[t-1]),f[t]=sol(a[t]);
	for(int i=t+1;i<=n;i++)
		f[i]=f[i-2]+f[i-1];
	return f[n].cnt;
}

int main(){
	scanf("%d%lld%d",&n,&k,&m);
	for(int i=1;i<=m&&k;i++){
		s.push_back(0);
		ll tmp=cal();
		if(tmp<k){
			k-=tmp;
			s[s.size()-1]=1;
		}
		cal();
		if(f[n].b[s.size()])
			k--;
	}
	for(auto x:s)
		printf("%d",x);
	puts("");
}