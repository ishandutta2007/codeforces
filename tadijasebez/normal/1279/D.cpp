#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

template<int mod> struct mod_int
{
	int x;
	mod_int<mod>(){ x=0;}
	mod_int<mod>(int _x):x(_x){}
	mod_int<mod> operator + (mod_int<mod> b) { b.x+=x;return mod_int<mod>(b.x>=mod?b.x-mod:b.x);}
	mod_int<mod> operator += (mod_int<mod> b) { return *this=*this+b;}
	mod_int<mod> operator += (int b) { x+=b;if(x>=mod) x-=mod;return *this;}
	mod_int<mod> operator - (mod_int<mod> b) { b.x-=x;return mod_int<mod>(b.x<0?b.x+mod:b.x);}
	mod_int<mod> operator -= (mod_int<mod> b) { return *this=*this-b;}
	mod_int<mod> operator -= (int b) { x-=b;if(x<0) x+=mod;return *this;}
	mod_int<mod> operator * (mod_int<mod> b) { return mod_int<mod>((ll)x*b.x%mod);}
	mod_int<mod> operator *= (mod_int<mod> b) { return *this=*this*b;}
	mod_int<mod> operator *= (int b) { x=(ll)x*b%mod;return *this;}
	mod_int<mod> pow(int k)
	{
		int y=x,ans=1;
		for(;k;k>>=1,y=(ll)y*y%mod) if(k&1) ans=(ll)ans*y%mod;
		return mod_int<mod>(ans);
	}
	mod_int<mod> inv() { return pow(mod-2);}
	mod_int<mod> operator / (mod_int<mod> b) { return (*this)*b.inv();}
	mod_int<mod> operator /= (mod_int<mod> b) { return *this=*this/b;}
};

int main()
{
	int n;
	scanf("%i",&n);
	vector<vector<int>> a(n,vector<int>());
	vector<int> cnt(1000001,0);
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%i",&k);
		a[i].resize(k);
		for(int &j:a[i]) scanf("%i",&j),cnt[j]++;
	}
	mod_int<998244353> ans,inv_n(n);
	ans.x=0;
	inv_n=inv_n.inv();
	for(int i=0;i<n;i++)
	{
		mod_int<998244353> inv_k(a[i].size()),tmp;
		tmp.x=0;
		inv_k=inv_k.inv();
		for(int j:a[i]) tmp+=cnt[j];
		tmp*=inv_k;
		ans+=tmp;
	}
	ans*=inv_n*inv_n;
	printf("%i\n",ans.x);
	return 0;
}