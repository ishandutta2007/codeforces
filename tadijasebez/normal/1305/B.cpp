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
const int N=1050;
char s[N];
int suf[N];
int main(){
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]+(s[i]==')');
	}
	int cnt=0;
	vector<int> pos,tmp;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			if(cnt+1<=suf[i+1]){
				cnt++;
				pos.pb(i);
			}
			else break;
		}
	}
	if(pos.empty()){
		printf("0\n");
		return 0;
	}
	printf("1\n%i\n",cnt*2);
	for(int i=n;i>=1;i--){
		if(s[i]==')' && cnt>0){
			cnt--;tmp.pb(i);
		}
	}
	reverse(tmp.begin(),tmp.end());
	for(int i:pos)printf("%i ",i);
	for(int i:tmp)printf("%i ",i);
	return 0;
}