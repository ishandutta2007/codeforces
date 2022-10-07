#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F(x,y)   (MIN(x-1,y-x+1))
using namespace std;
string s;
char ch;
int n,x,y;
ll ans;
int main(){
	while (1){
		ch=getchar();
		if(ch=='\n') break;
		if ('0'<=ch && ch<='9')s+=ch;
	}
	n=s.size();
	s="#"+s;
	x=s[1]-'0';
	if (x%4==0)ans++;
	for (int i=2;i<=n;i++){
		x=s[i-1]-'0';
		y=s[i]-'0';
		if (y%4==0)ans++;
		if ((x*2+y)%4==0)ans+=i-1;
	}
	cout<<ans<<endl;
	return 0;
}