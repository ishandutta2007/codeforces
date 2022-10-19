using namespace std;
#include<bits/stdc++.h>
char s[1000001];
int n;
int main() {
	cin>>n;
	scanf("%s",s);
	int cnt=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='0') {
			cout<<cnt;cnt=0;continue;
		}
		if(s[i]=='1') cnt++;
	}
//	if(s[n-1]!='0')
	cout<<cnt;
}