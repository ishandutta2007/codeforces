#include <bits/stdc++.h>
using namespace std;
string c;
int k;
int main() {
	cin>>c;
	cin>>k;
	int q=0,a=0;
	for(int i=0; i<c.size(); i++) {
		if(c[i]=='?')	q++;
		else if(c[i]=='*')	a++;
	}
	bool first=true;
	if(a==0&&k>c.size()-q)	puts("Impossible"),exit(0);
	if(k<c.size()-q*2-a*2)	puts("Impossible"),exit(0);
	if(k<(c.size()-q-a)) {
		if(k>=c.size()-q) {
			int count=c.size()-q-a-k;
			for(int i=0; i<c.size(); i++) {
				if(c[i+1]=='?'&&count>0) {
					count--;
					i++;
				} else if(c[i+1]=='?'&&count<=0)	cout<<c[i];
				else if(c[i]!='?'&&c[i]!='*') {
					cout<<c[i];
				}
			}
		} else if(k<c.size()-q) {
			int count=c.size()-a-q-k;
			for(int i=0; i<c.size(); i++) {
				if((c[i+1]=='?'||c[i+1]=='*')&&count>0) {
					count--;
					i++;
				} else if((c[i+1]=='?'||c[i+1]=='*')&&count<=0)	cout<<c[i];
				else if(c[i]!='?'&&c[i]!='*') {
					cout<<c[i];
				}
			}
		}
		exit(0);
	}
	for(int i=0; i<c.size(); i++) {
		if(c[i]=='*'&&first) {
			first=false;
			for(int j=0; j<(int)k-(c.size()-q-a); j++)
				putchar(c[i-1]);
		} else if(c[i]!='?'&&c[i]!='*')	putchar(c[i]);
	}
	return 0;
}