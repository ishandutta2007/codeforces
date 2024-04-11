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
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
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
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
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
const int N = 100005;
map<char,int> mp;
int num1[N],num2[N];char to[30];
char s[N];int n,k,cnt;
bool p[30];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i = 1;i <= n;++i)	p[s[i]-'a'+1] = true;
	for(int i = 1;i <= 26;++i)
		if(p[i]){mp['a'+i-1] = cnt;to[cnt] = 'a'+i-1;++cnt;}
	if(k <= n){
		for(int i = 1;i <= k;++i)num1[i] = mp[s[i]];
		num1[k]++;
		for(int i = k;i;--i)if(num1[i] == cnt)num1[i] = 0,num1[i-1]++;
		for(int i = 1;i <= k;++i)s[i] = to[num1[i]];
		s[k+1] = 0;
		printf("%s\n", s+1);
	}
	else{
		printf("%s",s+1);
		for(int i = 1;i <= k-n;++i)putchar(to[0]);
		puts("");
		return 0;
	}
	return 0;
}