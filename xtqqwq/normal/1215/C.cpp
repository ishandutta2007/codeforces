#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s1[200005],s2[200005];
vector<int> v[2];
vector<pii> ans;

int main(){
	n=readint();
	scanf("%s%s",s1+1,s2+1);
	int num=0;
	for(int i=1;i<=n;i++) num+=(s1[i]=='a')+(s2[i]=='a');
	if(num&1) return printf("-1\n"),0;
	for(int i=1;i<=n;i++) if(s1[i]!=s2[i]) v[s1[i]-'a'].push_back(i);
	if(v[0].size()&1){
		for(int i=1;i<v[0].size();i+=2) ans.push_back(mp(v[0][i],v[0][i+1]));
		for(int i=1;i<v[1].size();i+=2) ans.push_back(mp(v[1][i],v[1][i+1]));
		ans.push_back(mp(v[0][0],v[0][0]));
		ans.push_back(mp(v[0][0],v[1][0]));
	}
	else{
		for(int i=0;i<v[0].size();i+=2) ans.push_back(mp(v[0][i],v[0][i+1]));
		for(int i=0;i<v[1].size();i+=2) ans.push_back(mp(v[1][i],v[1][i+1]));
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}