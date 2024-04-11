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

char s[1000];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%s", s);
	int cnt = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
		s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9')
		cnt++;
	printf("%d\n", cnt);
}

void printans(){

}

int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}