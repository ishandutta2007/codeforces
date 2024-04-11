#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
const int N=3050;
const int mod=1e9+7;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
const int m1=998244353;
const int m2=977787779;
struct hsh
{
	int x,y;
	hsh(ll a=0):x(a%m1),y(a%m2){}
	hsh(int a, int b):x(a),y(b){}
	hsh operator + (hsh b){ return hsh((x+b.x)%m1,(y+b.y)%m2);}
	hsh operator - (hsh b){ return hsh((x-b.x+m1)%m1,(y-b.y+m2)%m2);}
	hsh operator * (hsh b){ return hsh((ll)x*b.x%m1,(ll)y*b.y%m2);}
	bool operator < (hsh b) const { return mp(x,y)<mp(b.x,b.y);}
	ll Get(){ return (ll)x*m2+y;}
};
unordered_set<ll> was[N];
hsh base(777);
int dp[N];
char s[N];
string merge(char a, char b, char c, char d)
{
	string ans="";
	ans+=a;ans+=b;ans+=c;ans+=d;
	return ans;
}
int main()
{
	int n,i,j,k,ans=0;
	scanf("%i",&n);
	set<string> bad;
	bad.insert("0011");
	bad.insert("0101");
	bad.insert("1110");
	bad.insert("1111");
	for(i=1;i<=n;i++)
	{
		scanf("\n%c",&s[i]);
		hsh tmp(0);
		dp[i+1]=1;
		for(j=i;j;j--)
		{
			tmp=tmp*base+hsh(s[j]-'a'+1);
			dp[j]=0;
			for(k=1;k<=4;k++) if(j+k<=i+1)
			{
				if(k==4 && bad.count(merge(s[j],s[j+1],s[j+2],s[j+3]))) continue;
				dp[j]=add(dp[j],dp[j+k]);
			}
			if(!was[i-j].count(tmp.Get()))
			{
				ans=add(ans,dp[j]);
				was[i-j].insert(tmp.Get());
			}
		}
		printf("%i\n",ans);
	}
	return 0;
}