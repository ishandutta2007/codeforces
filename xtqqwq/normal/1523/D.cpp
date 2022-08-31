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

int n,m,p;
int val[100005];
char s[200005][65];
mt19937 mrand(time(0)^(unsigned long long)(new char));

int main(){
	n=readint(); m=readint(); p=readint();
	for(int i=1;i<=n;i++) scanf("%s",s[i]);
	int ans=0; ll opt=0;
	for(int i=1;i<=20;i++){
		int pl=mrand()%n+1;
		vector<int> vec(0);
		for(int j=0;j<m;j++) if(s[pl][j]=='1') vec.pb(j);
		for(int j=0;j<(1<<vec.size());j++) val[j]=0;
		for(int j=1;j<=n;j++){
			int all=0;
			for(int k=0;k<vec.size();k++)
				if(s[j][vec[k]]=='1')
					all+=1<<k;
			val[all]++;
		}
		for(int j=0;j<vec.size();j++)
			for(int k=0;k<(1<<vec.size());k++)
				if(k&(1<<j))
					val[k^(1<<j)]+=val[k];
		int res=0,topt=0;
		for(int j=0;j<(1<<vec.size());j++)
			if(val[j]>=(n+1)/2)
				if(chkmax(res,__builtin_popcount(j)))
					topt=j;
		if(chkmax(ans,res)){
			ll tmp=0;
			for(int j=0;j<vec.size();j++)
				if(topt&(1<<j))
					tmp+=1ll<<vec[j];
			opt=tmp;
		}
	}
	for(int i=0;i<m;i++) printf("%d",(opt>>i)&1);
	printf("\n");
	return 0;
}