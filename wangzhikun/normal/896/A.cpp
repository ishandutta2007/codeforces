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
#define strlen(x) (x.length())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
string F0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string F1 = "What are you doing while sending \"";
string F2 = "\"? Are you busy? Will you send \"";
string F3 = "\"?";
ll inf = 1e18+10;
ll len[100010];
char gchar(int n,ll k){
	if(k>len[n])return '.';
	if(n == 0) return F0[k-1];
	if(k<=F1.length()) return F1[k-1];
	k-=F1.length();
	if(k<=len[n-1]) return gchar(n-1,k);
	else k-=len[n-1];
	if(k<=F2.length()) return F2[k-1];
	k-=strlen(F2);
	if(k<=len[n-1]) return gchar(n-1,k);
	else k-=len[n-1];
	return F3[k-1];
}
int main() {
	len[0] = strlen(F0);
	int add =  strlen(F1)+strlen(F2)+strlen(F3);
	for(int i=1;i<100010;i++){
		len[i] = min(inf,len[i-1]*2 + add);
	}
	int q;
	read(q);
	while(q--){
		int n;ll k;
		read(n);read(k);
		cout<<gchar(n,k);
	}
	cout<<endl;
	return 0;
}