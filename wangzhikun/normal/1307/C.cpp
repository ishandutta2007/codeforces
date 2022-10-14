#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

char s[100010];
ll poc[26] = {0},foc[26][26] = {0};
int main() {
	cin>>s;
	int n = strlen(s);
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++)foc[j][s[i]-'a']+=poc[j];
		poc[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		ans = max(ans,poc[i]);
		for(int j=0;j<26;j++)ans = max(ans,foc[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}