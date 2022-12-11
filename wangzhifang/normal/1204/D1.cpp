// LUOGU_RID: 93298021
#include <bits/stdc++.h>
using namespace std;
constexpr int max_n=100000;
char s[max_n+2];
int main(){
	scanf("%s",s+1);
	for(int i=strlen(s+1),sum=0; i; --i)
		if(s[i]=='0')
			++sum;
		else
			if(sum)
				--sum;
			else
				s[i]='0';
	printf("%s\n",s+1);
	return 0;
}