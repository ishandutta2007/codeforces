#include <bits/stdc++.h>
using namespace std;
char buf[256];
int main(){
	gets(buf);
	int len=strlen(buf)-1;
	while(!isalpha(buf[len]))	len--;
	if(buf[len]=='a'||buf[len]=='e'||buf[len]=='i'||buf[len]=='o'||buf[len]=='u'||buf[len]=='y'||buf[len]=='A'||buf[len]=='E'||buf[len]=='I'||buf[len]=='O'||buf[len]=='U'||buf[len]=='Y')
		cout<<"YES";
	else	cout<<"NO";
	return 0;
}