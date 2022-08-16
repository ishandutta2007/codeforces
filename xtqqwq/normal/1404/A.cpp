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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
int now[300005];
char s[300005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		scanf("%s",s+1);
		for(int i=1;i<=k;i++) now[i]=-1;
		bool fl=0;
		for(int i=1;i<=n;i++){
			int id=(i-1)%k+1;
			if(s[i]!='?'){
				if(now[id]==-1) now[id]=s[i]-'0';
				else if(now[id]!=s[i]-'0') fl=1;
			}
		}
		int cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=k;i++){
			if(now[i]==0) cnt0++;
			else if(now[i]==1) cnt1++;
			else cnt2++;
		}
		if(cnt0>k/2||cnt1>k/2) fl=1;
		if(fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}