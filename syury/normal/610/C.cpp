#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int k;

string invert(string s){
   for(int i = 0; i < s.length(); i++){
        s[i] = (s[i] == '+' ? '*' : '+');
   }
   return s;
}

vector<string> solve(int x){
    if(x == 1){
        vector<string> ans(2);
        ans[0] = "+*";
        ans[1] = "++";
        return ans;
    }
    vector<string> prev = solve(x - 1);
    vector<string> ans(1 << x);
    int half = (1 << x)/2;
    for(int i = 0; i < half; i++){
        ans[i] = prev[i] + prev[i];
        ans[i + half] = prev[i] + invert(prev[i]);
    }
    return ans;
}

vector<string> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> k;
	if(k == 0){
        cout << "+" << endl;
        return 0;
	}
	ans = solve(k);
	for(int i = 0; i < (1 << k); i++){
        cout << ans[i] << endl;
	}
	return 0;
}