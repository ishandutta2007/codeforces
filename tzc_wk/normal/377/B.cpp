#include <cassert>
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
#define LOCAL
using namespace std;
#define LL long long
#define FOR(i,a,b)	for(int i=(a);i<=(b);i++)
#define REP(i,n)	FOR(i,0,n-1)
#define FORD(i,a,b)	for(int i=(a);i>=(b);i--)
#define REPD(i,n)	FORD(i,n-1)
#define TYPE(v,s)	__typeof(i) v=i
#define FORE(i,c)	FOR(VAR(i,c.begin());i!=(c).end();i++)
#define X			first
#define Y			second
#define XX			X.X
#define XY			X.Y
#define YX			Y.X
#define YY			Y.Y
#define INS			insert
#define RSORT(st,ed)	{sort(st,ed);reverse(st,ed);}
#define CHECK	assert(0);
#ifdef LOCAL
	#define DEBUG(x)	cerr<<#x<<"="<<x<<endl;
	#define DEBUGA(x)	{cerr<<#x<<"=";FORE(itt,(x)) cerr<<*it<<"<";cerr<<endl;}
#endif
template<typename T> T abs(T x){return (x>=0)?(x):-x;}
#define MAXN		200010
typedef pair<int,int> PI;
typedef pair<int,PI> TPI;
typedef vector<int> VI;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >;
struct node{
    int sk, pr, id;
    bool operator <(node a) const{
        return pr>a.pr;
    }
};
bool cmp(node a, node b) {
    return a.sk > b.sk;
}
int n, m, cost, ans[MAXN];
node st[MAXN], pro[MAXN];
int check(int t) {
    int tmpcost = cost;
    priority_queue <node> q;
    for(int i = 1, j = 1; j<=m; j+=t) {
        while(i<=n&&st[i].sk>=pro[j].sk) {
            q.push(st[i]);
            i++;
        }
        if(q.empty()) {
            return 0;
        }
        tmpcost -= q.top().pr;
        FOR(tmp,j,min(j+t,m+1)){
            ans[pro[tmp].id] = q.top().id;
        }
        if(tmpcost<0)
            return 0;
        q.pop();
    }
    return 1;
}
int main(){
    cin>>n>>m>>cost;
    FOR(i,1,m){
        scanf("%d", &pro[i].sk);
        pro[i].id = i;
    }
    FOR(i,1,n){
        scanf("%d", &st[i].sk);
    }
    FOR(i,1,n){
        scanf("%d", &st[i].pr);
        st[i].id = i;
    }
    sort(pro+1, pro+1+m, cmp);
    sort(st+1, st+1+n, cmp);
    int flag = 0;
    for(int i = 1; i<=n; i++) {
        if(st[i].sk>=pro[1].sk&&st[i].pr<=cost)
            flag = 1;
    }
    if(!flag) {
        cout<<"NO"<<endl;
        return 0;
    }
    int l = 1, r = m, ret;
    while(l<=r) {
        int mid = l+r>>1;
        if(check(mid)) {
            r = mid-1;
            ret = mid;
        }
        else
            l = mid+1;
    }
    check(r+1);
    cout<<"YES"<<endl;
    for(int i = 1; i<=m; i++) {
        cout<<ans[i]<<" ";
    }
}