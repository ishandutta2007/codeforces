#include <bits/stdc++.h>
using namespace std;

int n, k, i, j;
string s;

int main(){
	scanf("%d",&n);
	for(i=0;i<26;i++){
		for(j=1;j*(j-1)/2<=n;j++)
			s.push_back('a'+i);
        j--; n -= j*(j-1)/2;
	}
	printf("%s\n",s.c_str());
	return 0;
}