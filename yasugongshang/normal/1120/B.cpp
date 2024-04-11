#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005;
vector<PI> ans;
ll tot;
int f[N],a[N],b[N];
char ch[N];
void check(){
	if(ans.size()==100000){
		for(auto i:ans){wri(i.first); writeln(i.second);} exit(0);
	}
}
void bao(int pos){
	assert(f[pos]);
	if(f[pos]>0){
		if(a[pos+1]==9)bao(pos+1);
		f[pos]--; a[pos]++; a[pos+1]++;
		ans.push_back(mp(pos,1)); check();
	}else{
		if(a[pos+1]==0)bao(pos+1);
		f[pos]++; a[pos]--; a[pos+1]--;
		ans.push_back(mp(pos,-1)); check();
	}
}
int main(){
	int n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)a[i]=ch[i]-'0';
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)b[i]=ch[i]-'0';
	ll tot=0;
	for(int i=1;i<=n;i++){
		f[i]=b[i]-a[i]-f[i-1]; tot+=abs(f[i]);
	}
	if(f[n]){
		puts("-1"); return 0;
	}
	cout<<tot<<endl;
	for(int i=1;i<n;i++){
		while(f[i]){
			bao(i);
		}
	}
	for(auto i:ans){
		wri(i.first);writeln(i.second);
	}
}