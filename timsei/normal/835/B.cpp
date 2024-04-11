#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200001;

char s[N];
int  m ,k;
int main() {
	cin>>k;
	scanf("%s",s);
	int l = strlen(s);
	int tot = 0;
	for(int i = 0 ;i <l;i ++) {
		tot +=s[i]- '0';
	}
	if(tot >= k) {
		cout<<0<<endl;return 0;
	}
	sort(s, s+ l);
	int ans = 0;
	for(int i= 0;i <l;i ++) {
		int wh = s[i] - '0';
		wh = 9 - wh;
		ans ++;
		tot +=wh;
		if(tot >= k) break;
	}
	cout<<ans<<endl;
}