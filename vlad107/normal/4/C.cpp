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

std::map<std::string,int> m;
char S[50];
std::string s;
int n;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d\n",&n);
	m.clear();
	for (int i=0;i<n;i++){
		gets(S);
		S[strlen(S)]=0;
		s=std::string(S);
		if (!m[s])
			puts("OK");
		else{
			for (int j=0;j<s.size();j++)
				putchar(s[j]);
			printf("%d\n",m[s]);
		}
		m[s]++;
	}
	return 0;
}