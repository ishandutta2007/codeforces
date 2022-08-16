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
int a[400005];
vector<int> v[2];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int res=0;
	for(int i=24;i>=0;i--){
		int ans=0;
		v[0].clear(),v[1].clear();
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)) v[1].push_back(a[j]&((1<<i)-1));
			else v[0].push_back(a[j]&((1<<i)-1));
		}
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		int now=v[0].size();
		for(int j=0;j<v[0].size();j++){
			while(now-1>=0&&v[0][now-1]+v[0][j]>=(1<<i)) now--;
			ans^=(v[0].size()-max(now,j+1))&1;
		}
		now=v[1].size();
		for(int j=0;j<v[1].size();j++){
			while(now-1>=0&&v[1][now-1]+v[1][j]>=(1<<i)) now--;
			ans^=(v[1].size()-max(now,j+1))&1;
		}
		now=v[1].size();
		for(int j=0;j<v[0].size();j++){
			while(now-1>=0&&v[1][now-1]+v[0][j]>=(1<<i)) now--;
			ans^=now&1;
		}
		res+=ans*(1<<i);
	}
	printf("%d\n",res);
	return 0;
}