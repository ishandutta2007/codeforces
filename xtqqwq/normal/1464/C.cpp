#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,t;
int cnt[100];
char s[100005];

int main(){
	n=readint(); t=readint();
	scanf("%s",s+1);
	t-=1<<(s[n]-'a');
	t+=1<<(s[n-1]-'a');
	for(int i=1;i<=n-2;i++) cnt[s[i]-'a']++;
	for(int i=0;i<=25;i++) t+=1ll*cnt[i]*(1<<i);
	if(t<0) return printf("No\n"),0;
	if(t&1) return printf("No\n"),0;
	t/=2;
	for(int i=0;i<=60;i++){
		if(t&1){
			if(cnt[i]==0) return printf("No\n"),0;
			cnt[i]--;
		}
		cnt[i+1]+=cnt[i]/2;
		t/=2;
	}
	printf("Yes\n");
	return 0;
}