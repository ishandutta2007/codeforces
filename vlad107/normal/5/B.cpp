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

int n=0,ml=0,q=0;
char S[10000];
std::string s[10000];

int main(){
//	freopen("in","r",stdin);
//	freopen("","w",stdout);
	while (gets(S)){
		S[strlen(S)]=0;
		s[n++]=std::string(S);
		if (s[n-1].size()>ml)ml=s[n-1].size();
	}
	for (int i=0;i<ml+2;i++)putchar('*');
	putchar('\n');
	for (int i=0;i<n;i++){
		putchar('*');
		int xs,ys;
		if ((ml-s[i].size())%2==0){
			xs=(ml-s[i].size())/2;
			ys=(ml-s[i].size())/2;
		}else{
			xs=(ml-s[i].size())/2;
			ys=(ml-s[i].size())/2;
			xs+=q;
			ys+=1-q;
			q=1-q;
		}
		for (int j=0;j<xs;j++)putchar(' ');
		for (int j=0;j<s[i].size();j++)putchar(s[i][j]);
		for (int j=0;j<ys;j++)putchar(' ');
		putchar('*');
		putchar('\n');
	}
	for (int i=0;i<ml+2;i++)putchar('*');
	putchar('\n');
	return 0;
}