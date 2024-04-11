#include<bits/stdc++.h>

using namespace std;

const int maxn=500007;

vector<int> nxt;
int a=0,b=0;

void get_nxt(string s){
	int j=-1;
	nxt.push_back(-1);
	for (auto c:s){
		while (j!=-1&&c!=s[j]) j=nxt[j];
		nxt.push_back(++j);
	}
}

void print(){
	for (int i=0;i<a;++i) printf("0");
	for (int i=0;i<b;++i) printf("1");
}

int main(){
	string s1,s2;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2;
	for (auto c:s1){
		if (c=='0') a++; else b++;
	}
	get_nxt(s2);
	int u=nxt[s2.size()];
	for (int i=0;i<u;++i){
		if (!a||!b){
			print();
			return 0;
		}
		if (s2[i]=='0') a--; else b--;
		printf("%c",s2[i]);
	}
	while (1){
		for (int i=u;i<s2.size();++i){
			if (!a||!b){
				print();
				return 0;
			}
			if (s2[i]=='0') a--; else b--;
			printf("%c",s2[i]);
		}
	}
	return 0;
}