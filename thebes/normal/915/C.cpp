#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int i, j, flag; string s, out;

bool rec(int p, int flag){
	if(p==s.size()) return 1;
	int mx = -1, pos = 0;
	for(int i=0;i<v.size();i++){
		if(!flag&&v[i]>mx){mx=v[i]; pos=i;}
		if(flag&&s[p]-'0'>=v[i]&&v[i]>mx){mx=v[i]; pos=i;}
	}
	if(flag && mx == -1) return 0;
	out.push_back(mx+'0'); v.erase(v.begin()+pos);
	if(rec(p+1,(mx==s[p]-'0'&&flag))==1) return 1;
	else{
		out.pop_back();
		v.push_back(mx); sort(v.begin(),v.end()); mx=-1;
		for(int i=0;i<v.size();i++){
			if(s[p]-'0'>v[i]&&v[i]>mx){mx=v[i]; pos=i;}
		}
		if(mx==-1) return 0;
		else{
			v.erase(v.begin()+pos);
			out.push_back(mx+'0');
			rec(p+1,0);
			return 1;
		}
	}
}

int main(){
	cin >> s;
	for(char c : s)
		v.push_back(c-'0');
	sort(v.begin(), v.end());
	cin >> s;
	while(s.size()-i>v.size()) i++;
	if(i) flag=0;
	else flag = 1;
	rec(i,flag);
	printf("%s\n",out.c_str());
	return 0;
}