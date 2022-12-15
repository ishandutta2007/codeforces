#include <bits/stdc++.h>
using namespace std;

string s;
int a[105], i, flag;

int main(){
	cin >> i >> s;
	for(i=0;i<s.size();i++){
		if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')&&flag) a[i]=1;
		else if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')) flag=1;
		else flag = 0;
	}
	for(i=0;i<s.size();i++)
		if(!a[i]) printf("%c",s[i]);
	return 0;
}