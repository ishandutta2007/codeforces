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
char s[1005];
bool vis[1005];
vector<vector<int> > ans;

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	while(1){
		int now=n;
		while(now>=1&&(s[now]!=')'||vis[now])) now--;
		vector<int> v1(0),v2(0);
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(s[i]=='('&&i<now){
				v1.push_back(i);
				v2.push_back(now);
				vis[i]=vis[now]=1;
				now--;
				while(now>=1&&(s[now]!=')'||vis[now])) now--;
			}
		}
		if(!v1.size()) break;
		for(int i=v2.size()-1;i>=0;i--) v1.push_back(v2[i]);
		ans.push_back(v1);
	}
	printf("%d\n",ans.size());
	for(auto v:ans){
		printf("%d\n",v.size());
		for(auto x:v) printf("%d ",x);
		printf("\n");
	}
	return 0;
}