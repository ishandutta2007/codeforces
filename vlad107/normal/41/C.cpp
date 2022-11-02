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

char s[1000];
std::string p="";
bool first=true;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	gets(s);
	p=s[0];
	for (int i=1;i<strlen(s);i++)
		if (i<strlen(s)-3&&s[i]=='d'&&s[i+1]=='o'&&s[i+2]=='t'){
			p+='.';
			i+=2;
		}else
		if (first&&i<strlen(s)-2&&s[i]=='a'&&s[i+1]=='t'){
			p+='@';
			i++;
			first=false;
		}else p+=s[i];
	for (int i=0;i<p.size();i++)
		putchar(p[i]);
	puts("");
	return 0;
}