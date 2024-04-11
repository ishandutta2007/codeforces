//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
string s;
int n;
bool check(string s){
	int l=0;
	while(l<s.size()&&s[l]==')')	l++;
	bool flag=1;
	fz(i,l,s.size())	if(s[i]==')'){
		flag=0;
	}
	if(flag)	return 1;
	return 0;
}
bool mark[1005];
signed main(){
	cin>>s;
	n=s.size();
	if(check(s))	return puts("0"),0;
	puts("1");
	fz(i,1,n){
		fill0(mark);
		int l=0,r=n-1;
		int cnt1=i,cnt2=i;
		bool is=1;
		while(l<n){
			if(s[l]=='('){
				if(mark[l]){
					is=0;
					break;
				}
				mark[l]=1;
				cnt1--;
				if(!cnt1)	break;
			}
			l++;
		}
		if(!is)	continue;
		if(cnt1)	continue;
		while(r>=0){
			if(s[r]==')'){
				if(mark[r]){
					is=0;
					break;
				}
				mark[r]=1;
				cnt2--;
				if(!cnt2)	break;
			}
			r--;
		}
		if(!is)	continue;
		if(cnt2)	continue;
		string ss;
		fz(j,0,n-1){
			if(!mark[j])	ss.push_back(s[j]);
		}
//		cout<<ss<<endl;
		if(check(ss)){
			vector<int> v;
			int ans=0;
			fz(j,0,n-1){
				if(mark[j])	v.push_back(j+1),ans++;
			}
			cout<<ans<<endl;
			foreach(it,v)	cout<<*it<<" ";
			return 0;
		}
	}
	return 0;
}