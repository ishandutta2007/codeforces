// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int cnt[26];
char s[200005];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<26;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) chkmax(cnt[s[i]-'a'],i);
		int ans=n+1;
		for(int i=0;i<26;i++) if(cnt[i]) chkmin(ans,cnt[i]);
		for(int i=ans;i<=n;i++) putchar(s[i]);
		putchar('\n');
	}
	return 0;
}