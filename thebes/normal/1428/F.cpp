#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 5e5+5;
int N, i, j, pre=1; ll ans, cur, acc;
string s;
stack<pii> stk;

int main(){
	cin >> N >> s;
	s.insert(s.begin(),' ');
	for(i=1;i<=N;i++){
		if(s[i]=='1'){
			int len = i-pre+1;
			ll hm = 1LL*len*(len+1)/2;
			while(stk.size()){
				if(stk.top().F<=len){
					acc += stk.top().S;
					cur -= 1LL*stk.top().F*stk.top().S;
					stk.pop();
				}
				else break;
			}
			ans += acc*len+hm+cur;
		}
		else{
			if(pre<i){
				int len = i-pre;
				cur += 1LL*len*(acc+1);
				stk.push({len,acc+1}); acc=0;
				for(j=len-1;j>=1;j--){
					cur += j;
					stk.push({j,1});
				}
			}
			stk.push({0,1});
			pre = i+1;
			ans += cur;
		}
	}
	printf("%lld\n",ans);
	return 0;
}