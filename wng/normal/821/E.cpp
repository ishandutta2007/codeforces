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
const long longprime=1000000007;


void mult(long long a[][16] ,long long b[][16] )
{
    long long c[16][16];
    REP(i,16)
    {
        REP(j,16)
        {
            c[i][j]=0;
            REP(k,16)
            {
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%longprime;
                }
            }
        }
        REP(i,16)
    {
        REP(j,16)
            {a[i][j]=c[i][j];}
        
    }
    }

int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);
  //  cout<<n<<" "<<k;
    long long mat[16][16];
    fill(mat[0],mat[0]+16*16,0);
    REP(i,16){
        mat[i][i]=1;
    }
 /*   REP(i,16){
        mat[i][i]=1;
    }*/
    REP(i,n){
        long long a,b;
        int c;
        scanf("%lld%lld%d",&a,&b,&c);
        long long mypow=min(b,k)-min(a,k);
        long long matpo[16][16];
        fill(matpo[0],matpo[0]+16*16,0);
        REP(j,c+1){
            if (j>0)
            {matpo[j][j-1]=1;}
            matpo[j][j]=1;
            if (j<c)
            {matpo[j][j+1]=1;}
        }
        while (mypow>0){
            long long mipo=mypow/2;
            long long mod=mypow-2*mipo;
      //      cout<<mod<<endl;
            mypow=mipo;
            if (mod==1){
                mult(mat,matpo);}
         /*   if (mypow<1000000000){
            REP(r,4){
                REP(c,4){
                    cout<<matpo[r][c]<<" ";
                }
                cout<<endl;
            }
                cout<<endl;}*/
            mult(matpo,matpo);
        }
    }

    cout<<mat[0][0];
}