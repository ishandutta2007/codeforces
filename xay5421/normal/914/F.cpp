#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,Q;
char s[N],t[N];
bitset<N>b[26],res;
int calc(bitset<N>&res,int l,int r){
	return (res>>l).count()-(res>>(r+1)).count();
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n){
		b[s[i]-'a'].set(i);
	}
	scanf("%d",&Q);
	while(Q--){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int i;
			char c;
			cin>>i>>c;
			b[s[i]-'a'].reset(i);
			s[i]=c;
			b[s[i]-'a'].set(i);
		}else{
			int l,r;
			scanf("%d%d%s",&l,&r,t+1);
			int t0=strlen(t+1);
			if(r-l+1<t0){
				puts("0");
				continue;
			}
			res.set();
			rep(i,1,t0){
				res&=b[t[i]-'a']>>(i-1);
			}
			cout<<calc(res,l,r-t0+1)<<'\n';
		}
	}
	return 0;
}