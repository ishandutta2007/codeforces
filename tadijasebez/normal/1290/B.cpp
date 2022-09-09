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
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb double
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
const int N=200050;
int cnt[26][N];
char s[N];
int main(){
	int n,q;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			cnt[j][i]=cnt[j][i-1]+(s[i]=='a'+j);
		}
	}
	scanf("%i",&q);
	while(q--){
		int l,r;
		scanf("%i %i",&l,&r);
		if(l==r)printf("Yes\n");
		else if(s[l]!=s[r])printf("Yes\n");
		else{
			int num=0;
			for(int j=0;j<26;j++)num+=cnt[j][r]!=cnt[j][l-1];
			if(num>=3)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}