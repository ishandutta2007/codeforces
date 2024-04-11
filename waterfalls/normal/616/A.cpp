#include <bits/stdc++.h>
using namespace std;

string a,b;
char buff[1000013];

int main() {
	for (int r=0;r<2;r++) {
		scanf(" %s",&buff);
		a = string(buff);
		reverse(a.begin(),a.end());
		swap(a,b);
	}
	while (a.size()>b.size()) b.push_back('0');
	while (b.size()>a.size()) a.push_back('0');
	int comp = 0;
	for (int i=0;i<a.size();i++) {
		if (a[i]<b[i]) comp = -1;
		if (a[i]>b[i]) comp = 1;
	}
	printf("%c\n",comp==0 ? '=' : comp==1 ? '>' : '<');

	return 0;
}