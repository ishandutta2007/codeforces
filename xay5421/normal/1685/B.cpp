#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
int T;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		int a,b,ba,ab;
		rd(a),rd(b),rd(ab),rd(ba);
		string s;
		cin>>s;
		int cnt_a=count(s.begin(),s.end(),'A');
		if(cnt_a!=a+ba+ab){puts("NO");continue;}
		int any=0;
		vector<int>v[2];
		for(int i=0,j=0;i<SZ(s);i=j){
			j=i+1;
			while(j<SZ(s)&&s[j]!=s[j-1])++j;
			if((j-i)&1){
				if(s[i]=='A'){
					--a;
					any+=(j-i-1)/2;
				}else{
					--b;
					any+=(j-i-1)/2;
				}
			}else{
				v[s[i]-'A'].pb(j-i);
			}
		}
		if(a<0||b<0){puts("NO");continue;}
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		rep(i,0,SZ(v[0])-1){
			int t=min(ab,v[0][i]/2);
			v[0][i]-=t*2;
			ab-=t;
			t=min(ba,v[0][i]/2-1);
			if(t>=0){
				v[0][i]-=t*2;
				ba-=t;
			}
		}
		rep(i,0,SZ(v[1])-1){
			int t=min(ba,v[1][i]/2);
			v[1][i]-=t*2;
			ba-=t;
			t=min(ab,v[1][i]/2-1);
			if(t>=0){
				v[1][i]-=t*2;
				ab-=t;
			}
		}
		if(ab+ba>any)puts("NO");else puts("YES");
	}
	return 0;
}