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
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;


int main(){
    long n;
    long p[1000002];
    LL dmoves[1000002]={0};
    RI(n);
    LL mr=0;
    REP(i,n){
        scanf("%ld",&p[i]);
        long pmkk=p[i]-i-1;
        mr+=abs(pmkk);
        if (pmkk<=0){
            dmoves[0]+=2;
            dmoves[n-i-1]-=2;
            dmoves[n-i-1]+=(2*p[i]-n-1)+1;
            if (i>0) {dmoves[n-i]-=(2*p[i]-n-1)+1;}
            if (pmkk<0){dmoves[n+pmkk]+=2;}
        }
        else
        {
            dmoves[pmkk]+=2;
            dmoves[n-i-1]-=2;
            dmoves[n-i-1]+=(2*p[i]-n-1)+1;
            if (i>0) {dmoves[n-i]-=(2*p[i]-n-1)+1;}
            }
    //        cout<<"on en est a "<<i<<endl;
  //  REP(i,n){cout<<i<<" "<<dmoves[i]<<endl;}
    }
  //  REP(i,n){cout<<i<<" "<<dmoves[i]<<endl;}
    
    long dm=-n;
    LL res=mr;
    long ress=0;
   // cout<<mr<<endl;
    REPP(i,1,n){
            dm+=dmoves[i-1];
            mr+=dm;
       //     cout<<res<<"  "<<mr<<" "<<dm<<" "<<dmoves[i-1]<<endl;
            if (res>mr)
            {
                res=mr;
                ress=i;
                }
        
        
        
        }
    
   cout<<res<<" "<<ress;
}