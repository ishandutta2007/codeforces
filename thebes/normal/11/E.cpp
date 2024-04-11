#include <bits/stdc++.h>
using namespace std;

string s, t;
double ans;

double solve(string s) {
	int a = 0, b = 0, c = 0, p = 0;
	for (int i = 0; i < s.size(); i ++) {
		char e = (b%2)?'R':'L';
		if (s[i] == 'X') b ++;
		else if (s[i] == e) a ++, b ++, p = 0;
		else a ++, b += 2, c += p, p = !p;
	}
	if (b%2) b++, c += p;
	if (a*2>b) a -= c, b -= 2 * c;
	return 100.0*a/b;
}

int main() {
	cin >> t;
	for(int i=0;i+1<t.size();i++){
        s += t[i];
        if(t[i]==t[i+1]&&t[i]!='X') s+='X';
	}
	s+=t.back();
	if(s[0]==s.back()&&s.back()!='X')
        ans=max(solve(s+'X'),solve('X'+s));
	else ans=solve(s);
	int f = ans*1000000;
	ans = f/1000000.0;
	printf("%.6lf\n",ans);
	return 0;
}