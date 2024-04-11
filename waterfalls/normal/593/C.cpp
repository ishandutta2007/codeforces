#include <bits/stdc++.h>
using namespace std;

string abs(string a) { return "abs("+a+")"; }
string add(string a, string b) { return "("+a+"+"+b+")"; }
string subtract(string a, string b) { return "("+a+"-"+b+")"; }
string multiply(string a, string b) { return "("+a+"*"+b+")"; }
string constant(int a) {
	if (a<0) return subtract("0",constant(-a));
	if (a<=50) return to_string(a);
	string res = "0";
	while (a>50) res = add(res,"50"), a-=50;
	return add(res,to_string(a));
}

string make(vector<int> x) {
	string res = "0";
	int on = 0;
	vector<int> has;
	for (int i: x) {
		string cur = subtract("t",constant(on));
		cur = add(cur,abs(cur));
		int prev = 0;
		for (int j=0;j<on;j++) prev+=2*(on-j+1)*has[j];
		if (prev%2!=i%2) i+=1;
		prev = (i-prev)/2;
		has.push_back(prev);
		cur = multiply(cur,constant(prev));
		on+=1;
		res = add(res,cur);
	}
	return res;
}

int n;
vector<int> x,y;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d%*d",&a,&b);
		x.push_back(a);
		y.push_back(b);
	}
	printf("%s\n",make(x).c_str());
	printf("%s\n",make(y).c_str());

	return 0;
}