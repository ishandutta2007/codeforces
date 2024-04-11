#include <bits/stdc++.h>
using namespace std;
const int N=100;
char s[N];
bool was[N];
int main(){
	int n;scanf("%i",&n);
	scanf("%s",s);
	string t="aeiouy";
	for(int i=0;i<n;i++){
		for(char c:t)if(c==s[i])was[i]=1;
	}
	for(int i=0;i<n;i++)if(!was[i]||(i==0||!was[i-1]))printf("%c",s[i]);
	return 0;
}