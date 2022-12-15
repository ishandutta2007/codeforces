#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 3e5+5;
int T, N, i, j, x, f1, f2, ans;
string s;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		cin >> s;
		f1 = f2 = 0;
		for(auto c : s){
			if(c=='<') f1 = 1;
			if(c=='>') f2 = 1;
		}
		ans = 0;
		for(i=0;i<N;i++){
			if(!f1||!f2) ans ++;
			else{
				int pre = (i-1+N)%N;
				if(s[pre]=='-'||s[i]=='-') ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}