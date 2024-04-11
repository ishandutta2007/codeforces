#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
string ans;
struct dat{
	string s;
	char sp;
	int id;
}a[210];

bool check(string s){
	//cout<<s<<endl;
	rep(i,1,n-1){
		//cout<<s.substr(0,i)<<" "<<s.substr(n-i)<<endl;
		if(a[2*i-1].s==s.substr(0,i)&&a[2*i].s==s.substr(n-i)){
			a[2*i-1].sp = 'P'; a[2*i].sp = 'S';
		}else if(a[2*i].s==s.substr(0,i)&&a[2*i-1].s==s.substr(n-i)){
			a[2*i].sp = 'P'; a[2*i-1].sp = 'S';
		}else return false;
	}
}

bool cmp(dat a,dat b){return a.s.size()<b.s.size();}
bool cmp2(dat a,dat b){return a.id<b.id;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,2*n-2){
		cin>>a[i].s;
		a[i].id = i;
	}
	sort(a+1,a+n*2-1,cmp);
	if(check(a[1].s+a[2*n-2].s))ans = a[1].s+a[2*n-2].s;
	else if(check(a[2].s+a[2*n-2].s))ans = a[2].s+a[2*n-2].s;
	else if(check(a[2*n-2].s+a[1].s))ans = a[2*n-2].s+a[1].s;
	else if(check(a[2*n-2].s+a[2].s))ans = a[2*n-2].s+a[2].s;
	sort(a+1,a+n*2-1,cmp2);
	rep(i,1,2*n-2)cout<<a[i].sp;
	cout<<endl;
	return 0;
}