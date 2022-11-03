#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define mod 10000
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
string str;
int a[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(int argc, char const *argv[]) {
	int x = read();
	cin >> str;
	cin >> str;
	if (str == "week") {
		if (x == 5 || x == 6)
			puts("53");
		else
			puts("52");
	} else {
		int ans = 0;
		for (int i = 0; i < 12; i++)
			if (x <= a[i]) ans ++;
		printf("%d\n", ans);
	}
	return 0;
}