template<class T>struct _iter_wrapper{T begin_,end_;T begin(){return begin_;}T end(){return end_;}};
template<class T>_iter_wrapper<const T*>span(const T*arr, int n){return _iter_wrapper<const T*>{arr,
arr+n};} template<class T, int N>_iter_wrapper<const T*>span(const T(&arr)[N]) {return span(arr,N);}
#define _deb(...)(_printDebug/*                               */(__LINE__,#__VA_ARGS__,__VA_ARGS__))
#define rep(i,b,e)/*                                                      */for(int i=(b);i<(e);i++)
#define sz(x)/*                                                                    */int((x).size())
#define mp/*                                                                             */make_pair
#include/*                                                                         */<bits/stdc++.h>
#ifdef/*                                                                                       */LOC
#define/*                                                                                 */deb _deb
#elif/*                                                                                       */true
#define/*                                                                                 */deb(...)
#endif/*                                                                                          */
#define/*                                                                                  */x first
#define/*                             ("`-''-/").___..--''"`-._                           */y second
#define pb/*                          `6_ 6  )   `-.  (     ).`-.__.`)                   */push_back
#define each(a,x/*                    (_Y_.)'  ._   )  `._ `. ``-..-`             */)for(auto&a:(x))
#define all(x)(x)/*                  _..`--'_..-_/  /--'_.' ,'                  */.begin(),(x).end()
#define DBP(...)void print(/*      (il),-''  (li),'  ((!.-'    */...){DD(#__VA_ARGS__,__VA_ARGS__);}
using namespace std;using namespace rel_ops;using ll=long long;using ull=unsigned long long;using Vi
=vector<int>;using Vll=vector<ll>;using Vull=vector<ull>; using Pii=pair<int,int>; template<class T,
class V> auto operator<<(T& out,V val)->decltype(val.print(0),out){out<<"{";val.print();return out<<
"}";}template<class T, class V>auto operator<<(T&out,V val)->decltype(get<1>(val), out){return out<<
"("<<val.x<<", "<<val.y<<")";} template<class T,class V>auto operator<<(T &out,V val)->decltype(all(
val),out){out << "[";bool comma=false;for(auto elem:val){if(comma)out << ", ";out<<elem;comma=true;}
return out<<"]";}void DD(...){}template<class T,class...S>void DD(const char*format,T elem,S...rest)
{int braces=0;while(*format&&(braces>0||*format!=',')){if(*format=='('||*format=='['||*format=='{'||
*format=='<'){braces++;}if (*format==')'||*format==']'||*format=='}'||*format=='>') braces--;cerr<<*
format++;} cerr<<": "<<elem<<*format++;DD(format, rest...);} template<class...T>void _printDebug(int
line,const char*format, T...elems){cerr<<'<';if(line<10)cerr<<'0';if(line<100)cerr<<'0';cerr<<line<<
"> ";DD(format,elems...);cerr<<endl;}void run();int main(){cin.sync_with_stdio(0); cin.tie(0);cout<<
fixed<<setprecision(/*<**************************><**************************>*/10);run();return 0;}
//------------------------------------------------------------------------------------------------//

// testing submit script

void run() {
	int n, m; cin >> n >> m;
	Vi elems(n), wallet(m);

	each(x, elems) cin >> x;
	each(x, wallet) cin >> x;

	int i = 0;

	each(elem, elems) {
		if (i >= m) break;
		if (wallet[i] >= elem) i++;
	}

	cout << i << endl;
}