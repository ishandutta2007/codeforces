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

int n;
char s[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s+1);
		int now1=0,now2=0,fl=0,sum=0,cnt=0;
		for(int i=1;i<=n;i++) if(s[i]=='1') cnt++;
		if(cnt&1){
			printf("NO\n");
			continue;
		}
		vector<int> ans1(0),ans2(0);
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				if(sum<cnt) now1++,now2++,ans1.pb(0),ans2.pb(0),sum+=2;
				else now1--,now2--,ans1.pb(1),ans2.pb(1);
			}
			else{
				if(now1>now2) now1--,now2++,ans1.pb(1),ans2.pb(0);
				else now1++,now2--,ans1.pb(0),ans2.pb(1);
			}
			if(now1<0||now2<0) fl=1;
		}
		if(fl){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			for(auto r:ans1) putchar(r==0?'(':')');
			puts("");
			for(auto r:ans2) putchar(r==0?'(':')');
			puts("");
		}
	}
	return 0;
}