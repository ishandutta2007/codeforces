#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ld long double
#define PI pair<int,int>
#define F first
#define S second
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
const int N=300005;
int n,k,zs[N];
vector<PI> v[N];
pair<ll,ll> check(int x){
	ll ans1=0,ans2=0,tot=0; int sum=0,dq=0;
	memset(zs,0,sizeof(zs));
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			if(j.F<=dq){
				sum+=j.S; tot+=(ll)(dq-j.F+1)*j.S;
			}else{
				zs[j.F]+=j.S;
			}
		}
		while(dq<i&&sum+zs[dq+1]>=x){sum+=zs[++dq]; tot+=sum;}
		ans1+=dq; ans2+=tot; //cout<<ans1<<" "<<dq<<" "<<zs[1]<<endl;
	}
	return mp(ans1,ans2);
}
struct data{
	int l,r,id;
};
bool operator <(data a,data b){
	return a.l==b.l?a.r<b.r:a.l<b.l;
}
multiset<data> s;
void split(int pos){
	auto it=s.lower_bound((data){pos,0,0});
	if(it!=s.begin())it--; else return;
	if((*it).l>pos||(*it).r<pos)return;
	if((*it).l<pos)s.insert((data){(*it).l,pos,(*it).id});
	if(pos<(*it).r)s.insert((data){pos,(*it).r,(*it).id});
	s.erase(it);
}
void insert(int l,int r,int id){
	for(auto it=s.lower_bound((data){l,0,0});it!=s.end()&&(*it).r<=r;){v[id].push_back(mp((*it).id+1,((*it).r-(*it).l))); s.erase(it++);}
	v[id].push_back(mp(id+1,l-r));
	s.insert((data){l,r,id});
}
signed main(){
	n=read(); k=read();
	s.insert((data){1,1000000000,0});
	for(int i=1;i<=n;i++){
		int l=read(),r=read();
		split(l); split(r);
		//for(auto j:s)cout<<j.l<<" "<<j.r<<" "<<j.id<<endl;
		insert(l,r,i);
		//for(auto j:v[i])cout<<j.F<<" wzp "<<j.S<<endl;
	}
	//cout<<check(3).first<<endl; return 0;
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(check(mid).first>=k)l=mid; else r=mid-1;
	}
	cout<<check(l).second-(check(l).first-k)*l<<endl;
}