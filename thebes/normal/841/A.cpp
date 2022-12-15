#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 105;
int N, K, i, j, cnt[26];
string s;

int main(){
	scanf("%d%d",&N,&K);
	cin >> s;
	for(auto c : s){
		cnt[c-'a']++;
	}
	for(i=0;i<26;i++){
		if(cnt[i]>K){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}