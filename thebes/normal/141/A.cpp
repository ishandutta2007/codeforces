#include <bits/stdc++.h>
using namespace std;

int a[26], b[26], i, flag;
string s, t, wts;

int main(){
	cin>>s>>t>>wts;
	for(char c:s) a[c-'A']++;
	for(char c:t) a[c-'A']++;
	for(char c:wts) b[c-'A']++;
	for(i=0;i<26;i++)
		if(a[i]!=b[i]) flag=1;
	printf("%s\n",(flag)?"NO":"YES");
	return 0;
}