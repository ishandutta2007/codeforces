#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 1111

using namespace std;

int n,cA[77],cB[77];
bool used[N],found;
string a[N],b[N];
char BUFF[11];

string getS(){
	char c=getchar();
	while (((c<'A')||(c>'Z'))&&((c<'a')||(c>'z')))c=getchar();
	string s="";
	while (((c>='A')&&(c<='Z'))||(c>='a')&&(c<='z')){
		s+=c;
		c=getchar();
	}
	return s;
}

void putS(string s){
	for (int i=0;i<s.size();i++)putchar(s[i]);
}

int main(){
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)a[i]=getS();
	for (int i=0;i<n;i++)b[i]=getS();
	sort(a,a+n);
	sort(b,b+n);
	for (int i=0;i<n;i++){
		++cA[a[i][0]-'A'];
		++cB[b[i][0]-'A'];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if ((used[j])||((a[i][0]!=b[j][0])&&((cB[b[j][0]-'A']<=cA[b[j][0]-'A'])||(cA[a[i][0]-'A']<=cB[a[i][0]-'A']))))continue;
			used[j]=true;
			--cA[a[i][0]-'A'];
			--cB[b[j][0]-'A'];
			putS(a[i]+" "+b[j]);
			if (i<n-1)printf(", ");else puts("");
			break;
		}
	}
}