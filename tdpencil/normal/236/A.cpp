#include <bits/stdc++.h>
using  namespace std;
#define ll long long
#define vi vector<int>
#define si set<int>
#define pii pair<int, int>
#define vp vector<pii>
#define mii map<int, int>
#define ss set<string>
#define sc set<char>
#define sii set<pii>
#define ms(val,  str, size) memset(val, str,size)
#define PB push_back
#define SI size()
#define ins insert
ll n, b, a;
int main(){
	string s;
	cin >> s;
	set<char> j;
	for(int i=0;i<s.size();i++){
		j.ins(s[i]);
	}
	cout<<(j.size()%2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}