#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

char str[6000];
int n;

int main() {
	scanf("%s",str);
	n=strlen(str);
	int a=0,b=0,c=0,f=0;
	if(str[0]!='a') {
		puts("NO");
		return 0;
	}
	for(int i=0;i<n;i++) {
		if(str[i]-'a' != f) {
			if(str[i]-'a'-1 !=f) {
				f=-1;
				break;
			}
			f++;
		}
		if(f==0) a++;
		else if(f==1) b++;
		else c++;
	}
	if(f==-1) {
		puts("NO");
		return 0;
	}
	if(a>0 && b>0 && (a==c || b==c)) {
		puts("YES");
		return 0;
	}
	else puts("NO");
	return 0;
}