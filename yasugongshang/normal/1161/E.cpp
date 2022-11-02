#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
int gg[N],col[N],q[N];
char res[N];
int vis[N];
int main(){
	int T=read();
	while(T--){
		int n=read();
		if(n>1){
			cout<<"Q "<<n/2<<" ";
			for(int i=1;i<n;i+=2){
				wri(i); wri(i+1);
			}
			cout<<endl;
			scanf("%s",res);
			for(int i=1;i<n;i+=2)vis[i]='1'-res[i/2];
		}
		if(n>2){
			cout<<"Q "<<(n-1)/2<<" ";
			for(int i=2;i<n;i+=2){wri(i); wri(i+1);}
			cout<<endl;
			scanf("%s",res);
			for(int i=2;i<n;i+=2)vis[i]='1'-res[i/2-1];
		}
		q[*q=1]=1;
		for(int i=1;i<n;i++)if(vis[i])q[++*q]=i+1;
		if(*q>=3){
			vector<PI> v;
			for(int i=1;i+2<=*q;i+=4){
				v.push_back(mp(i,i+2));
				if(i+3<=*q)v.push_back(mp(i+1,i+3));
			}
			cout<<"Q "<<v.size()<<" ";
			for(auto i:v){wri(q[i.fi]); wri(q[i.se]);}
			cout<<endl;
			scanf("%s",res);
			int dq=0;
			for(int i=1;i+2<=*q;i+=4){
				gg[i]=res[dq++];
				if(i+3<=*q)gg[i+1]=res[dq++];
			}
			if(*q>=4){v.clear();
			for(int i=3;i+2<=*q;i+=4){
				v.push_back(mp(i,i+2));
				if(i+3<=*q)v.push_back(mp(i+1,i+3));
			}
			cout<<"Q "<<v.size()<<" ";
			for(auto i:v){wri(q[i.fi]); wri(q[i.se]);}
			cout<<endl;
			scanf("%s",res);
			dq=0;
			for(int i=3;i+2<=*q;i+=4){
				gg[i]=res[dq++];
				if(i+3<=*q)gg[i+1]=res[dq++];
			}}
		}
		col[1]=1; col[2]=2;
		for(int i=1;i+2<=*q;i++)if(gg[i]=='1')col[i+2]=col[i];
		else col[i+2]=6-col[i]-col[i+1];
		q[*q+1]=n+1;
		vector<int> ans[4];
		For(i,1,*q)For(j,q[i],q[i+1]-1)ans[col[i]].push_back(j);
		cout<<"A "<<ans[1].size()<<" "<<ans[2].size()<<" "<<ans[3].size()<<endl;
		For(i,1,3){
			for(auto j:ans[i])wri(j); cout<<endl;
		}
	}
}