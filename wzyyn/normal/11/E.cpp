#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
string s,ss;
double ans;
void tryitry(string s){
	int x=0,y=0,o=0,fl=0;
	int l=s.length();
	For(i,0,l-1){
		char ch=((i+y)&1?'R':'L');
		if (s[i]=='X') continue;
		if (s[i]==ch) ++x,fl=0;
		else ++x,++y,o+=fl,fl^=1;
	}
	y+=l;
	if (y&1) y++,o+=fl;
	if (x*2>y) x-=o,y-=2*o;
	ans=max(ans,1.0*x/y);
}
int main(){
	cin>>s;
	int l=s.length();
	For(i,0,l-1){
		if (i&&s[i]!='X'&&s[i]==s[i-1])
			ss+='X';
		ss+=s[i];
	}
	if (ss[0]==ss[ss.length()-1]&&ss[0]!='X')
		tryitry('X'+ss),tryitry(ss+'X');
	else tryitry(ss);
	printf("%.6lf\n",max(0.00,ans*100-(0.499)*(1e-6)));
}