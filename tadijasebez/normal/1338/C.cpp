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
const int N=100050;
ll a[N],ans[N];
int idx[N];
int main(){
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++)scanf("%lld",&a[i]),idx[i]=i;
	sort(idx+1,idx+1+q,[&](int i,int j){return a[i]<a[j];});
	ll sz=1,pos=1;
	ll hh[4]={0,1,2,3};
	ll ff[4]={0,2,3,1};
	ll gg[4]={0,3,1,2};
	for(int j=1;j<=q;j++){
		int i=idx[j];
		while(pos+3*sz<=a[i]){
			pos+=3*sz;
			sz*=4;
		}
		ll dif=a[i]-pos;
		ll mul=dif%3+1;
		ans[i]+=mul*sz;
		dif/=3;
		//printf("%i %i\n",dif,mul);
		ll po=1;
		while(dif){
			if(mul==1)ans[i]+=hh[dif%4]*po;
			if(mul==2)ans[i]+=ff[dif%4]*po;
			if(mul==3)ans[i]+=gg[dif%4]*po;
			po*=4;
			dif/=4;
		}
		/*if(mul==1){
			ans[i]=sz*mul+dif/3;
		}else{
			dif/=3;
			ans[i]=sz*mul+(dif-dif%4)*mul;

		}
		ll res=sz*mul;
		ll tmp=dif/3;
		res+=(tmp-tmp%4)*mul;
		if(mul==)
		ans[i]=res;*/
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}