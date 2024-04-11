// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2014 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <clltypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdll>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=1LL*(x)*(y)%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        prllf("~%lld~\n",x)
#define pp(x,y)     prllf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  prllf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	prllf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
using namespace std;
const ll N=400010;
struct lbc1{ll pos,w;}ask[N];
struct dt{ll l,r,id,cur;}w[N];
ll ctc,q,n,Q,a[N],lbc[N],sum[N],answ[N],zyy;
map<ll,ll>mp;
bool cmp(dt a,dt b){
	return a.l/3000==b.l/3000?(a.r/3000==b.r/3000?a.cur<b.cur:a.r/3000<b.r/3000):a.l<b.l;
}
void updata(ll x,ll y){
	--lbc[sum[x]],sum[x]+=y,++lbc[sum[x]];
}
void change(ll x,ll l,ll r){
	if (ask[x].pos>=l&&ask[x].pos<=r)updata(a[ask[x].pos],-1);
	swap(a[ask[x].pos],ask[x].w);
	if (ask[x].pos>=l&&ask[x].pos<=r)updata(a[ask[x].pos],1);
}
ll ASK(){
	ll qqq=1;
	for(;lbc[qqq];++qqq);
	return qqq;
}
void solve(){
	ll l=1,r=1,xiu=0;updata(1,1);
	For(i,1,q){
		for(;r<w[i].r;++r)			updata(a[r+1],1);
		for(;r>w[i].r;--r)			updata(a[r],-1);
		for(;l<w[i].l;++l)			updata(a[l],-1);
		for(;l>w[i].l;--l)			updata(a[l-1],1);
		for(;xiu<w[i].cur;++xiu)	change(xiu+1,l,r);
		for(;xiu>w[i].cur;--xiu)	change(xiu,l,r);
		answ[w[i].id]=ASK();
	}
}
ll read(){ll x;scanf("%I64d",&x);return x;}
void write(ll x){printf("%I64d",x);}
void writeln(ll x){printf("%I64d\n",x);}
int main(){
//	freopen("cf.in","r",stdin);
	n=read(),Q=read();
	For(i,1,n)a[i]=read(),a[i]=mp[a[i]]?mp[a[i]]:(mp[a[i]]=++ctc);
//	For(i,1,n)write(a[i]),putchar(' ');puts("");
	For(i,1,Q){
		if(read()==2){
			ask[++zyy].pos=read();
			ask[zyy].w=read();
			ask[zyy].w=mp[ask[zyy].w]?mp[ask[zyy].w]:(mp[ask[zyy].w]=++ctc);
		}else{
			w[++q].l=read();w[q].r=read();
			w[q].id=q;w[q].cur=zyy;
		}
	}sort(w+1,w+q+1,cmp);
	solve();
	For(i,1,q)writeln(answ[i]);
}