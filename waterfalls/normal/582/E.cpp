#include <bits/stdc++.h>
using namespace std;

int n;
char s[513];

const int MOD = 1e9+7;

int dp[1<<16];
vector<int> go(vector<int> x, int rev=1) {
	for (int i=0;i<(1<<16);i++) dp[i] = x[i];
	for (int i=0;i<16;i++) {
		for (int j=0;j<(1<<16);j++) if (!(j&(1<<i))) {
			dp[j] = (dp[j]+rev*dp[j^(1<<i)])%MOD;
		}
	}
	for (int i=0;i<(1<<16);i++) x[i] = (dp[i]+MOD)%MOD;
	return x;
}

void add(vector<int> one, vector<int> two, vector<int>& res, char op) {
	if (op=='|') {
		reverse(one.begin(),one.end());
		reverse(two.begin(),two.end());
		reverse(res.begin(),res.end());
	}
	one = go(one);
	two = go(two);
	vector<int> cur(1<<16);
	for (int i=0;i<(1<<16);i++) cur[i] = ((long long) one[i]*two[i])%MOD;
	cur = go(cur,-1);
	for (int i=0;i<(1<<16);i++) res[i] = (res[i]+cur[i])%MOD;
	if (op=='|') reverse(res.begin(),res.end());
}

vector<int> solve(int l, int r) {
	vector<int> res(1<<16);
	if (l==r) {
		for (int k=0;k<8;k++) {
			int j = k%4;
			if (s[l]!='?' && s[l]!=(k/4 ? 'A' : 'a')+j) continue;
			int has = 0;
			for (int i=0;i<16;i++) if ((k/4)^!(i&(1<<j))) has|=(1<<i);
			res[has] = 1;
		}
	} else {
		int mid = l+1;
		int cnt = 0;
		while (true) {
			if (s[mid-1]=='(') cnt+=1;
			if (s[mid-1]==')') cnt-=1;
			if (cnt==0) break;
			mid+=1;
		}
		vector<int> one = solve(l+1,mid-2);
		vector<int> two = solve(mid+2,r-1);
		if (s[mid]!='&') add(one,two,res,'|');
		if (s[mid]!='|') add(one,two,res,'&');
	}
	return res;
}

int main() {
	scanf(" %s",&s);
	vector<int> ways = solve(0,strlen(s)-1);
	int on = 0;
	int off = 0;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if (e) on|=1<<((d<<3)|(c<<2)|(b<<1)|a);
		else off|=1<<((d<<3)|(c<<2)|(b<<1)|a);
	}
	int ans = 0;
	for (int i=0;i<(1<<16);i++) {
		if ((i&on)!=on || (~i&off)!=off) continue;
		ans = (ans+ways[i])%MOD;
	}
	printf("%d\n",ans);

	return 0;
}