#include <bits/stdc++.h>
using namespace std;
int n;
int qry(int x) {
	if(x<1||x>n) return 1e9;
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int u; cin>>u;
	return u;
}
void work(int l,int r) {
	if(l==r) {
		cout<<"! "<<l<<endl;
		exit(0);
	}
	int m=(l+r)>>1;
	int fm=qry(m);
	if(fm>qry(m+1)) work(m+1,r);
	if(fm>qry(m-1)) work(l,m-1);
	cout<<"! "<<m<<endl;
	exit(0);
}
int main()
{
	cin>>n;
	work(1,n);
}