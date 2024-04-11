#include <bits/stdc++.h>
using namespace std;
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,k,a[100005],cnt[100005],ans,fac[100005];
vector<pair<int,int> > g[100005];
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		for(int j=2;j*j<=tmp;j++)
			if(tmp%j==0){
				int sum=0;
				while(tmp%j==0){
					sum++;
					tmp/=j;
				}
				g[i].push_back({j,sum});
			}
		if(tmp!=1){
			fac[tmp]++;
			g[i].push_back({tmp,1});
		}
		int mul=1;
		for(int j=0;j<g[i].size();j++){
			while(g[i][j].second%k!=0){
				mul*=g[i][j].first;
				g[i][j].second++;
				if(mul>100000)
					break;
			}
		}
		if(mul>100000){
			continue;
		}
		int cur=1;
		while(1){
			int x=mul;
			for(int f=1;f<=k;f++){
				x*=cur;
				if(x>100000)	break;
			}
			if(x>100000){
				break;
			}
			if(x!=a[i])		ans+=cnt[x];
			else			ans+=max(cnt[x]-1,0ll);
			cur++;
		}
	}
	print(ans>>1);
    return 0;
}