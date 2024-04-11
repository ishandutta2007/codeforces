#include <bits/stdc++.h>

using namespace std;

int n;
set <string> S;

char tell(char a, char b){
	if(a == 'k' && b == 'h')
		return 'h';
	if(a == 'o' && b == 'o')
		return 'u';
	return 0;
}

int main(){
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		string ret;
		for(int i = 0; i < s.size(); ++i){
			char cur = s[i];
			while(true){
				if(ret.size() == 0)
					break;

				char change = tell(ret[ret.size() - 1], cur);
				if(change == 0)
					break;
			
				cur = change;
				ret.pop_back();
			}
			
			if(cur == 'u' && (ret.size() > 0 && ret[ret.size() - 1] == 'o')){
				ret.push_back('o');
				ret[ret.size() - 2] = 'u';
			}
			else
				ret.push_back(cur);
		}
		
		S.insert(ret);
	}
	
	cout << S.size();
	return 0;
}