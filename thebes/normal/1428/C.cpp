#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2e5+5;
stack<char> stk;
int T, i, N, cnt, hm;
string s;

int main(){
	scanf("%d",&T);
	while(T--){
		cin >> s;
		N = (int)s.size(); cnt = hm = 0;
		while(stk.size()) stk.pop();
		for(i=0;i<N;i++){
			if(s[i]=='B'){
				if(stk.size()&&stk.top()=='A') stk.pop();
				else stk.push('B');
			}
			else stk.push('A');
		}
		int pre = -1;
		while(stk.size()){
			cnt ++;
			if(stk.top()=='B'&&pre==1){
				pre = 0;
				cnt -= 2;
			}
			else if(stk.top()=='B') pre = 1;
			else pre = 0;
			stk.pop();
		}
		printf("%d\n",cnt);
	}
	return 0;
}