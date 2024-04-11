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

bool head;
char s[1000],p[1000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	gets(s);
	head=true;
	for (int i=0;i<strlen(s);i++)
		if (s[i]!='/'){
			head=false;
			break;
		}
	if (head){
		printf("/\n");
		return 0;
	}
	while (s[strlen(s)-1]=='/')s[strlen(s)-1]=0;
	int kp=1;
	p[0]='/';
	for (int i=1;i<strlen(s);i++){
		if(s[i]=='/'&&s[i-1]=='/')continue;
		p[kp++]=s[i];
	}
	p[kp]=0;
	puts(p);
	return 0;
}