#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>
#include <functional>

int res=0,kol=0;
char S[1000];
std::string s;

int main(){
//	freopen("in","r",stdin);
//	freopen("","w",stdout);
	while (gets(S)){
		S[strlen(S)]=0;
		s=std::string(S);
		if (s[0]=='+'||s[0]=='-')
			kol+=(s[0]=='+')?+1:-1;
		int q=s.find(':'),o=s.size();
		if (q>-1){
			res+=(s.size()-q-1)*kol;
		}
	}
	printf("%d\n",res);
	return 0;
}