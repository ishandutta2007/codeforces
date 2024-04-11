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
#define Fi first
#define Sn second
typedef long long LL;
using namespace std;


bool isin(long s, unordered_map<long,long> &m){
    return (m.find(s)!=m.end());
}


long deuxpownmodprime(long n,long mod){
    n=(n%(mod-1));
    long res;
    res = 1;
    if (n&1){res=2;}
    if (n<=1) {return res;}
    long ps2=deuxpownmodprime(n/2,mod);
    long long resll;
    resll=res;
    resll*=ps2;
    resll*=ps2;
    return (resll%mod);
}

int main(){
    long totf=0;
    int n;
    RI(n);
    int decomps[71]={0, 0, 1, 2, 0, 4, 3, 8, 1, 0, 5, 16, 2, 32, 9, 6, 0, 64, 1, 128, 4, 10, 17, 256, 3, 0, 33, 2, 8, 512, 7, 1024, 1, 18, 65, 12, 0, 2048, 129, 34, 5, 4096, 11, 8192, 16, 4, 257, 16384, 2, 0, 1, 66, 32, 32768, 3, 20, 9, 130, 513, 65536, 6, 131072, 1025, 8, 0, 36, 19, 262144, 64, 258, 13};
    
    long mod= 1000000000+7;
    unordered_map<long,long> ot;
    long nbm=(1<<19);
   // long tot[nbm]={0};
    ot.insert(pair<long,long> (0,1));
    int dn[71]={0};    
    REP(i,n){
        int a;
        RI(a);
        dn[a]++;
    }
    REP(i,71)
    {
        if (dn[i]>0){
            totf+=dn[i]-1;
            int a=decomps[i];
            unordered_map<long,long> ta;
            for (auto it : ot){
                long m=(it.Fi)^a;
                bool j=isin(m,ta);
                if (!j){
                    ta.insert(pair<long,long> (m,it.Sn));
                }
                else{
                    ta[m]+=it.Sn;
                    //ot[it.Fi]=ot[m];
                }
            }
            for (auto it: ta)
            {
                if (!isin(it.Fi,ot)){
                    ot[it.Fi]=it.Sn;
                }
                else{
                    ot[it.Fi]=(it.Sn+ot[it.Fi])%mod;
                }
            }
        }
    }
    long long c=ot[0];
    c*=deuxpownmodprime(totf,mod);
    cout<<(c-1)%mod<<endl;
}