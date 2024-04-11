#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <cstring>

using namespace std;

char str[51];

int get(char ch) {
	if(ch=='a') return 0;
	else if(ch=='e') return 1;
	else if(ch=='i') return 2;
	else if(ch=='o') return 3;
	else if(ch=='u') return 4;
	else return -1;
}
int ch_chk[10],num_chk[10];
int main() {
	scanf("%s",str);
	
	int n=strlen(str),cnt=0;
	for(int i=0;i<n;i++) {
		if(str[i]>='0' && str[i]<='9') {
			if(str[i]=='1' || str[i]=='3' || str[i]=='5' || str[i]=='7' || str[i]=='9') cnt++;
		}
		else {
			int idx=get(str[i]);
			if(idx!=-1) cnt++;
		}
	}
	printf("%d\n",cnt);
	
	return 0;
}