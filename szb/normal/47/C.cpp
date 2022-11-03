#include <bits/stdc++.h>
#define ll int
#define inf 2000000001
#define maxn 11000
#define mod 100000000
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
vector<string>ans;
string s[6];
bool add(char &a,char b){
	if (a!='.'&&a!=b)	return 0;
	a=b;	return 1;
}
int main(){
	For(i,0,5)	cin>>s[i];
	sort(s,s+6);
	do{
		vector<string>v(s[0].size(),string(s[1].size(),'.'));
		if (s[0].size()!=s[4].size()+s[3].size()-1) continue;
		if (s[1].size()!=s[2].size()+s[5].size()-1) continue;
		bool fl=1;
		For(i,0,s[0].size()-1)	fl&=add(v[i][s[2].size()-1],s[0][i]);
		For(i,0,s[1].size()-1)	fl&=add(v[s[3].size()-1][i],s[1][i]);
		For(i,0,s[2].size()-1)	fl&=add(v[0][i],s[2][i]);
		For(i,0,s[3].size()-1)	fl&=add(v[i][0],s[3][i]);
		For(i,0,s[4].size()-1)	fl&=add(v[s[3].size()-1+i][s[1].size()-1],s[4][i]);
		For(i,0,s[5].size()-1)	fl&=add(v[s[0].size()-1][s[2].size()-1+i],s[5][i]);
		if (!fl)	continue;
		if (ans.empty()||v<ans)	ans=v;
	}while (next_permutation(s,s+6));
	if (ans.empty())	cout<<"Impossible"<<endl;
	else	for(auto i:ans) cout<<i<<endl;
}