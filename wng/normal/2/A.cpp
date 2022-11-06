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

bool isin(string s, map<string,long> m){
    return (m.find(s)!=m.end());
}

int main(){
    int n;
    map <string,long> score;
    vector<pair<string,int>> rounds;
    RI(n);
   // cout<<n<<endl;
      REP(i,n){
          char nc[32];
        string nom;
        int ds=0;
       scanf("%s %d",nc,&ds);
       nom=nc;
     //   cout<<nom<<" "<<ds<<endl;
         if (isin(nom,score)){
            score[nom]+=ds;
        }
        else{
            score[nom]=ds;
        }
        rounds.PB(MP(nom,ds));/**/
    }
   map<string, long>::iterator it;
   long maxs=-100000000;
   vector<string> Nwinners;
  for(it=score.begin();it!=score.end();it++)
    {
        long sc=it->S;
        if(sc>=maxs){
            if (sc>maxs)
            {
                maxs=it->S;
                Nwinners.resize(0);
            }
            Nwinners.PB(it->F);
        }
    //    cout<<it->F<<" "<<it->S<<endl;
    } /**/
    
    string res;
    if (Nwinners.size()==1){
        res=Nwinners[0];
    }
    else{
        
    map <string,long> scorer;
    REP(i,Nwinners.size()){
   //         cout<<Nwinners[i]<<" "<<score[Nwinners[i]]<<endl;
            scorer[Nwinners[i]]=0;
        }
    REP(i,rounds.size()){
        if (score[rounds[i].F]==maxs){
            scorer[rounds[i].F]+=rounds[i].S;
            if (scorer[rounds[i].F]>=maxs){
                res=rounds[i].F;
                break;
            }
        }
    }
    }
    cout<<res<<endl;
}