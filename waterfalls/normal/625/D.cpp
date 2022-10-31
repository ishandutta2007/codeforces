#include <bits/stdc++.h>
using namespace std;

char buff[100013];
vector<int> s, ans;

bool solve(bool lcarries, bool rcarried=0) {
	ans = vector<int>(s.size());
	for (int i=s.size()-1;i>=(int) s.size()/2;i--) {
		int j = s.size()-1-i;
		int rval = s[i]-rcarried;
		if (i==j) {
			if (lcarries) rval+=10;
			if (rval%2!=0) return false;
			ans[i] = rval/2;
		} else if (rval<0) {
			rval+=10;
			ans[j] = 9;
			ans[i] = 0;
			lcarries = lcarries;
			if (s[j]!=(s[i]-rcarried+lcarries+10)%10) return false;
			rcarried = 1;
		} else {
			if (rval<9 && lcarries) rval+=10;
			ans[j] = min(9,rval);
			ans[i] = rval-min(9,rval);
			if (rval==9) lcarries = lcarries;
			else {
				if (s[j]==(s[i]-rcarried+0+10)%10) lcarries = 0;
				else if (s[j]==(s[i]-rcarried+1+10)%10) lcarries = 1;
				else return false;
			}
			if (s[j]!=(s[i]-rcarried+lcarries+10)%10) return false;
			if (rval==9) rcarried = rcarried;
			else rcarried = (rval>=10);
		}
	}
	if (s.size()%2==0 && lcarries!=rcarried) return false;
	for (int i: ans) printf("%d",i);
	printf("\n");
	return true;
}

int main() {
	scanf(" %s",&buff);
	for (int i=0;buff[i]!='\0';i++) s.push_back(buff[i]-'0');
	if (s[s.size()-1]==0 || !solve(0)) {
		if (s[0]==1 && s.size()>1) {
			s.erase(s.begin());
			if (!solve(1)) printf("0\n");
		} else printf("0\n");
	}

	return 0;
}