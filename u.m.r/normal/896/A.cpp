#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string t1 =  "What are you doing while sending \"";
string t2 = "\"? Are you busy? Will you send \"";
string t3 = "\"?";
ll K;

ll len[1000];
ll limit;

ll gL(int n){
	if (n <= 53)
		return len[n];
	else
		return limit + 1;
}

char gao(int n, ll K){
	//cout << "??? " << n << ' ' << K << endl;
	if (n == 0){
		if (K < s.length())
			return s[K];
		else
			return '.';
	}
	if (K < t1.length())
		return t1[(int)K];
	if (K < gL(n-1) + t1.length())
		return gao(n-1, K - t1.length());
	if (K < gL(n-1) + t1.length() + t2.length())
		return t2[(int)(K - t1.length() - gL(n-1))];
	if (K < gL(n-1) + t1.length() + t2.length() + gL(n-1))
		return gao(n-1, K - t1.length() - t2.length() - gL(n-1));
	if (K < t3.length() + gL(n-1) + t1.length() + t2.length() + gL(n-1))
		return t3[(int)(K - gL(n-1) - t1.length() - t2.length() - gL(n-1))];
	else
		return '.';
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%lld", &n, &K);
	K--;
	putchar(gao(n, K));
}

void printans(){

}

int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	len[0] = s.length();
	limit = 1000000000;
	limit *= limit;
	for (int j = 1; j <= 53; j++){
		len[j] = 2 * len[j - 1] + t1.length() + t2.length() + t3.length();
	}
	int T = 1;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	puts("");
	return 0;
}