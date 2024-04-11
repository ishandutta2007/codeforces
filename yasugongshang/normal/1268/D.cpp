#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int N=2005;
int n,cnt[1<<6|2],d[N],e[N],ans[10],sum;
char ch[N];
bitset<N> s[N];
bool check(int *a){
	static int jb[N]; mem(jb);
	For(i,0,n-1)jb[a[i]]++;
	int sum=0,cnt=0;
	Rep(i,n,0){
		For(j,1,jb[i]){
			sum+=i; cnt++; //cout<<sum<<" fjz "<<cnt<<endl;
			if(cnt<n&&sum==cnt*(cnt-1)/2+cnt*(n-cnt))return 0;
		}
	}
	//For(i,0,n-1)wri(a[i]); puts("");
	return 1;
}
int main(){
	n=read();
	For(i,0,n-1){
		scanf("%s",ch);
		For(j,0,n-1)d[i]+=(s[i][j]=(ch[j]=='1'));
	}
	if(n<=6){
		For(i,0,(1<<n)-1){
			mem(d);
			cnt[i]=cnt[i>>1]+(i&1);
			For(j,0,n-1)For(k,0,n-1)d[j]+=s[j][k]^(i>>j&1)^(i>>k&1);
			ans[cnt[i]]+=check(d);
		}
		For(i,0,n)if(ans[i]){For(j,1,i)ans[i]=ans[i]*j; cout<<i<<" "<<ans[i]<<endl; exit(0);}
		puts("-1");
	}else{
		if(check(d)){puts("0 1"); exit(0);}
		For(i,0,n-1){
			memcpy(e,d,sizeof(d));
			For(j,0,n-1)if(s[j][i])e[j]--; else e[j]++;
			e[i]=n-1-d[i];
			sum+=check(e);
		}
		cout<<1<<" "<<sum<<endl;
	}
}