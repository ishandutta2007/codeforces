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
const int N=1000050;
int n;
char s[N];
bool Check(int l,int r){
	int bal=0;
	for(int i=l;i<=r;i++){
		if(s[i]==')'){
			bal--;
		}else bal++;
		if(bal<0)return 0;
	}
	return bal==0;
}
int main(){
	scanf("%i %s",&n,s+1);
	int bal=0,las=0,ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==')')bal--;
		else bal++;
		if(bal==0){
			if(!Check(las+1,i))ans+=i-las;
			las=i;
		}
	}
	if(las!=n)printf("-1\n");
	else printf("%i\n",ans);
	return 0;
}