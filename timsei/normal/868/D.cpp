#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int Max = 30;

set<string>S[N][Max];
set<string> :: iterator it;
int n , m;
string s[N] , st[N] , en[N];

int main(void) {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) {
		cin>>s[i]; st[i] = en[i] = s[i];
		for(int j = 0;j < s[i].length();j ++) {
			string str = "";
			for(int k = j;k < s[i].length();k ++) {
				str.push_back(s[i][k]);
				S[i][str.length()].insert(str);
				if(str.length() > 20) break;
			}
		}
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++) {
		int x , y;
		scanf("%d%d",&x,&y);
		if(st[x].length() < 20)st[i + n] = st[x] + st[y]; else st[i + n] = st[x]; 
		en[i + n] = en[y];if(en[y].length() < 20) en[i + n] = en[x] + st[y];
		string str = en[x] + st[y];
		for(int  j = 0;j < Max;j ++) {
			for(it = S[x][j].begin();it != S[x][j].end();it ++) S[i + n][j].insert(*it);
			for(it = S[y][j].begin();it != S[y][j].end();it ++) S[i + n][j].insert(*it);
		}
		for(int j = 0;j < str.length();j ++) {
			string now = "";
			for(int k = j;k < str.length();k ++) {
				now.push_back(str[k]);
				S[i + n][now.length()].insert(now);
				if(now.length() > 20) break;
			}
		}
		
		int p = 0;
		for(int j = 1;j <= 20;j ++) if(S[i + n][j].size() == (1 << j)) {
			p = j;
		}
		cout<<p<<endl;
	}
}