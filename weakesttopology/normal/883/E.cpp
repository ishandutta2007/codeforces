#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;

void test_case(){
	int n, m;
	cin >> n;
	string str, str1;
	cin >> str;
	vi v(26, 1);
	for(auto c: str){
		if(c!='*')v[c-'a']=0;
	}
	cin >> m;
	vector<string> words;
	for(int i = 0; i < m; i++){
		cin >> str1;
		bool ok = true;
		for(int j = 0; j < n; j++){
			if((str[j]!='*' && str[j] != str1[j])||(str[j]=='*' && !v[str1[j]-'a'])){
				ok = false;
				break;
			}
		}
		if(ok){
			words.push_back(str1);
		}
	}
	for(auto s: words){
		vi v_aux(26);
		for(auto c: s)v_aux[c-'a']=1;
		for(int j = 0; j < 26; j++)if(!v_aux[j])v[j]=0;
	}
	int cnt = 0;
	for(auto x: v)if(x==1)cnt++;
	cout << cnt << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}