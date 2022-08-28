//CF1045H
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
const int MO = 1e9+7;
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%MO;
	if(y&1)
		z=z*x%MO;
	return z;
}
int f[N],g[N];
int C(int x,int y){
	if(x<0||y<0||x<y)
		return 0;
	return (LL)f[x]*g[y]%MO*g[x-y]%MO;
}
int E(int x,int y){
	if(!x&&!y)
		return 1;
	return C(x+y-1,y-1);
}
int n,aa,bb,cc,dd;
int a,b,c,d;
int T(int z){
	if(a<0||b<0||c<0||d<0)
		return 0;
	if(z){
		if(b==c||b==c-1)
			return (LL)E(a,c)*E(d,b+1)%MO;
		return 0;
	}
	else{
		if(b==c||b==c+1)
			return (LL)E(a,c+1)*E(d,b)%MO;
		return 0;
	}
}
int solve(string s){
	a=aa,b=bb,c=cc,d=dd;
	int l=s.length(),ans=0,i;
	if(n>l)
		return 0;
	if(n<l)
		return T(1);
	for(i=1;i<n;i=i+1){
		if(s[i]=='1'){
			if(s[i-1]=='0')
				a--;
			else
				c--;
			ans=(ans+T(0))%MO;
			if(s[i-1]=='0')
				a++,b--;
			else
				c++,d--;
		}
		else{
			if(s[i-1]=='0')
				a--;
			else
				c--;
		}
	}
	ans=(ans+T(s[n-1]-'0'))%MO;
	return ans;
}
string s,t;
int main()
{
	int i;
	n=1e5+15;
	f[0]=1;
	for(i=1;i<=n;i=i+1)
		f[i]=(LL)f[i-1]*i%MO;
	g[n]=fpow(f[n]);
	for(i=n;i;i=i-1)
		g[i-1]=(LL)g[i]*i%MO;
	cin>>s>>t>>aa>>bb>>cc>>dd;
	n=1+aa+bb+cc+dd;
	for(i=s.length()-1;s[i]=='0';i=i-1)
		s[i]^=1;
	s[i]^=1;
	if(s[0]=='0')
		s=s.substr(1,s.length());
	cout<<(solve(t)+MO-solve(s))%MO;
	return 0;
}