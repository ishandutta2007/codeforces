//CF1465B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,p,q,a[N],t[N];
char s[N];
void ad(int x){
	while(x<=n){
		t[x]++;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
vector<int> v;
LL ans,c,e;
void chk(){//cout<<c<<e<<endl;
	ans=min(ans,e*(LL)p+(c*(n-c)-e)*(LL)q);
}
int main()
{
	int i;
	scanf("%s%d%d",s+1,&p,&q);
	n=strlen(s+1);
	for(i=1;i<=n;i=i+1){
		if(s[i]=='?')
			v.push_back(i);
	}
	ans=2e18;
	c=0,e=0;
	for(i=1;i<=n;i=i+1){
		if(s[i]=='1'){
			ad(i);
			c++;
			e+=i-qu(i);
		}
	}
	chk();
	for(i=0;i<v.size();i=i+1){
		ad(v[i]);
		c++;
		e+=v[i]-c;
		chk();
	}
	memset(t,0,sizeof(t));
	reverse(v.begin(),v.end());
	c=0,e=0;
	for(i=1;i<=n;i=i+1){
		if(s[i]=='1'){
			ad(i);
			c++;
			e+=i-qu(i);
		}
	}
	chk();
	for(i=0;i<v.size();i=i+1){
		ad(v[i]);
		c++;
		e+=v[i]-c;
		chk();
	}
	cout<<ans;
	return 0;
}