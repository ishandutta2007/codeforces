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


//1. Determine radius r of circumcircle : its product of the sides / (4xarea of triangle)
//2. Determine number n of polygons, it's the pgdc of the 3 angles or something.
//3. Determine area of arena, it's  r^2*n*sin(2pi/n)/2


double area(double x1,double x2,double y1,double y2,double z1,double z2){
    return abs(0.5*(x1*(y2-z2)+y1*(z2-x2)+z1*(x2-y2)));
}

double dist(double x1,double x2,double y1,double y2){
    return sqrt(pow((x1-y1),2)+pow(x2-y2,2));
}

double angle(double a,double b,double c){
    return acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
}


double pgcd (double m, double n)
{
  return (abs(n)<pow(10,-6))?(m):(pgcd( n,fmod(m+0.5*pow(10,-6),n))-0.5*pow(10,-6));
}

bool divise(double m,double n,double prec=0.5*pow(10,-6))
{
    return abs(fmod(m+prec,n)-prec)<prec;
}

int main(){
    double x1,x2,y1,y2,z1,z2;
//    cout<<x1<<" "<<x2<<endl;
    scanf("%lf%lf",&x1,&x2);
    scanf("%lf%lf",&y1,&y2);
    scanf("%lf%lf",&z1,&z2);
    cout.precision(12);
 //   cout<<x1<<" "<<x2<<endl;
 //   cout<<y1<<" "<<y2<<endl;
//    cout<<z1<<" "<<z2<<endl;
    double At=area(x1,x2,y1,y2,z1,z2);
 //    cout<<At<<endl;
    double a,b,c;
    a=dist(x1,x2,y1,y2);
    b=dist(y1,y2,z1,z2);
    c=dist(x1,x2,z1,z2);
//    cout<<a<<" "<<b<<" "<<c<<endl;
    double rc=(a*b*c)/(4*At);
//    cout<<rc<<endl;
    //angles
    double A,B,C;
    A=angle(a,b,c);
    B=angle(b,c,a);
    C=angle(c,b,a);
   //  cout<<A<<" "<<B<<" "<<C<<endl;
    double pi=3.14159265358979;
//    double nbsides=pi/pgcd(A,pgcd(B,C));
    long nbs;//=(long)(nbsides+0.5);
    REP(i,3000){
        if (divise(A,pi/(i+1)) && divise(B,pi/(i+1)) && divise(C,pi/(i+1)))
        {
            nbs=i+1;
            break;
        }
    }
    double res=pow(rc,2)*nbs*sin(2*pi/nbs)/2;
 //    cout<<pgcd(A,pgcd(B,C))<<" "<<nbsides<<" "<<nbs<<" "<<rc<<" "<<res<<endl;
    cout<<res<<endl;
}