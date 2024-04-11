#include <bits/stdc++.h>
using namespace std;

string s; priority_queue<int> pos;
int n, k, i;
int main(){
	cin >> n >> k >> s;
	for(i=0;i<s.size();i++)
		if(s[i]=='('&&s[i+1]==')') pos.push(i);
	while(s.size()>k){
		int c = pos.top(); pos.pop();
		s.erase(s.begin()+c);
		s.erase(s.begin()+c);
		if(c-1>=0&&s[c-1]=='('&&s[c]==')') pos.push(c-1);
	}
	cout << s.c_str();
	return 0;
}