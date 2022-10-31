#include <bits/stdc++.h>
using namespace std;

int n;
char buff[100013];
string base = "1";
string zeros;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		if (buff[0]=='0') return printf("0\n"), 0;
		bool ok = (buff[0]=='1');
		for (int j=1;buff[j]!='\0';j++) {
			if (buff[j]!='0') ok = 0;
		}
		if (ok) zeros+=string(buff).substr(1,strlen(buff)-1);
		else base = string(buff);
	}
	printf("%s\n",(base+zeros).c_str());

	return 0;
}