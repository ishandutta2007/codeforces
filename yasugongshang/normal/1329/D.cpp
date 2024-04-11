#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
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
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;  
const int N=200005;
char ch[N];
int q[N];
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>::iterator it;
set<int> S[26];
pair<int,int> get(int x,int y){
	int X=s.order_of_key(x)+2,Y=X;
	for(auto it=s.upper_bound(x);it!=s.end()&&*it<=y;s.erase(it++))Y++;
	//cout<<x<<" "<<y<<" "<<X<<" "<<Y<<" "<<s.size()<<endl;
	return mp(X,Y-1);
}
int main(){
	int T=read();
	while(T--){
		cin>>(ch+1);
		vector<pair<int,int> > ans;
		set<int> SS;
		s.clear();
		int n=strlen(ch+1);
		For(i,1,n)s.insert(i);
		For(i,1,n-1)if(ch[i]==ch[i+1]){
			ch[i]-='a';			
			S[ch[i]].insert(i);
			SS.insert(i);
		}
		while(1){
			int p=-1,mx=-1,pp=-1;
			//cout<<S[2].size()<<" "<<((int)S[2].size()>mx)<<endl;
			For(i,0,25)if(SZ(S[i])>mx){
				mx=S[i].size(); p=i;
			}
			For(i,0,25)if(i!=p&&S[i].size())pp=i;
			if(pp<0)break;
			//cout<<p<<" "<<mx<<" "<<pp<<" "<<S[pp].size()<<endl;
			int qq=*S[pp].begin();
			auto it=S[p].lower_bound(qq);
			if(it!=S[p].end()){
				auto jj=SS.find(*it); jj--; qq=*jj;
				ans.pb(get(*jj,*it));
			}else{
				it--; auto jj=SS.find(*it); jj++; qq=*jj;
				ans.pb(get(*it,*jj));
			}
			S[p].erase(it); SS.erase(*it);
			S[ch[qq]].erase(qq); SS.erase(qq);
		}
		For(i,0,25)if(S[i].size()){
			auto it=S[i].begin();
			For(j,1,S[i].size()){q[j]=*it; it++;} q[S[i].size()+1]=n;
			For(j,1,S[i].size())ans.pb(get(q[1],q[j+1]));
			S[i].clear();
		}
		ans.pb(mp(1,s.size()));
		writeln(ans.size());
		for(auto i:ans){
			wri(i.fi); writeln(i.se);
		}
	}
}