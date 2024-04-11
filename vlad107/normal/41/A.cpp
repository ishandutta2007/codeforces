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

char s[1000],p[1000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	gets(s);gets(p);
	for (int i=0,j=strlen(p)-1;i<j;i++,j--)
		std::swap(p[i],p[j]);
	if (std::string(s)!=std::string(p))
		puts("NO");
	else puts("YES");
	return 0;
}