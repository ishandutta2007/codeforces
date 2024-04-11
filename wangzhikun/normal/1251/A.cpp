#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n;
int main() {
	read(n);
	for(int i=0;i<n;i++){
		int ok[30] = {0};
		char s[1010];
		cin>>s;
		int m = strlen(s);
		for(int j=0;j<m;j++){
			if(j!=0 && s[j] == s[j-1])continue;
			int k=j;
			while(s[k+1] == s[j])k++;
			if((k-j+1)%2 == 1)ok[s[j]-'a'] = 1;
		}
		for(int j=0;j<26;j++){
			if(ok[j])putchar('a'+j);
		}
		putchar('\n');
	}
	return 0;
}