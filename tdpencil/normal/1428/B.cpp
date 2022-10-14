#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int TC; cin >> TC;
	while(TC--){
		int n; cin >> n;
		string s; cin >> s;
		
		bool hasCW = false;
		bool hasCCW = false;
		for(int i = 0;i < n;i++){
			if(s[i] == '<') hasCW = true;
			if(s[i] == '>') hasCCW = true;
		}
		
		if(hasCW && hasCCW){
			int ans = 0;
			s += s[0];
			for(int i = 0;i < n;i++){
				if(s[i] == '-' || s[i+1] == '-') ans++;
			}
			cout << ans << "\n";
		}
		else{
			cout << n << "\n";
		}
	}
}