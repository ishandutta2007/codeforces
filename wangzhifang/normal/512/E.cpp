#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <set>
#define cs const
#define max_n 1000
using namespace std;
typedef cs int& ci;
int buf[max_n+1];
set<int> s[max_n+1];
struct node{
	int a,b;
	node(){}
	node(ci _a,ci _b):a(_a),b(_b){}
};
node ans[max_n<<1],*answ;
void solve(ci l,ci r){
	if(r==l+1)
		return;
	int tmp=*--s[l].lower_bound(r);
	s[1].insert(tmp),s[tmp].insert(1),
	s[l].erase(r),s[r].erase(l),
	*++answ=node(l,r);
	solve(l,tmp),
	solve(tmp,r);
}
void isolve(ci l,ci r){
	if(r==l+1)
		return;
	int tmp=*--s[l].lower_bound(r);
	s[1].insert(tmp),s[tmp].insert(1),
	s[l].erase(r),s[r].erase(l),
	*++answ=node(1,tmp);
	isolve(l,tmp),
	isolve(tmp,r);
}
template<typename T>void read(T&x){
	int ch;
	while(!isdigit(ch=getchar()));
	for(x=ch^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
}
template<typename T1,typename T2>void read(T1&x,T2&y){
	read(x);
	read(y);
}
template<typename T>void write(cs T&x){
	if(x>=10)
		write(x/10);
	putchar((x%10)|'0');
}
template<typename T>void write(cs T&x,cs char&ch){
	write(x);
	putchar(ch);
}
template<typename T>void writeln(cs T&x){
	write(x,'\n');
}
template<typename T1,typename T2>void writeln_sp(cs T1&x,cs T2&y){
	write(x,' ');
	writeln(y);
}
int main(){
	int n;
	read(n),answ=ans;
	for(int i=1; ++i<n; s[i].insert(i+1),s[i].insert(i-1));
	s[1].insert(2),s[1].insert(n),
	s[n].insert(1),s[n].insert(n-1);
	for(int i=n-2,a,b; --i; s[a].insert(b),s[b].insert(a))
		read(a,b);
	int cnt=0;
	for(set<int>::iterator it=s[1].begin(),ed=s[1].end(); it!=ed; ++it)
		buf[cnt++]=*it;
	for(int i=0; ++i<cnt; solve(buf[i-1],buf[i]));
	node*tmp=answ;
	for(int i=0; ++i<=n; s[i].clear());
	for(int i=1; ++i<n; s[i].insert(i+1),s[i].insert(i-1));
	s[1].insert(2),s[1].insert(n),
	s[n].insert(1),s[n].insert(n-1);
	for(int i=n-2,a,b; --i; s[a].insert(b),s[b].insert(a))
		read(a,b);
	cnt=0;
	for(set<int>::iterator it=s[1].begin(),ed=s[1].end(); it!=ed; ++it)
		buf[cnt++]=*it;
	for(int i=0; ++i<cnt; isolve(buf[i-1],buf[i]));
	writeln(answ-ans);
	for(node*i=ans; ++i<=tmp; writeln_sp(i->a,i->b));
	for(node*i=answ+1; --i>tmp; writeln_sp(i->a,i->b));
	return 0;
}