#include<iostream>
using namespace std;
#define ll long long
#include <set>
int main(){
	int n,l,r,p;ll prev;
	cin>>n;
	 ll a[100002],s[100002];
	cin>>a[0];
	s[0]=a[0];
	for (ll i = 1; i < n; ++i)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	set<ll> set1;
	multiset<ll>mset1;
	set1.insert(-1);
	set1.insert(n);
	mset1.insert(s[n-1]);
	//mset1.insert(s[n-1]);
	for (ll i = 0; i < n; ++i)
	{
		cin>>p;
		p--;
		set1.insert(p);
		auto it=set1.find(p);
		it--;
		l=*(it);
		set<ll>::iterator its=set1.find(p);
		its++;
		r=*(its);
		//cout<<l<<"   "<<r<<endl;
		prev=s[r-1];
		if(l!=-1)
			prev-=s[l];
		//cout<<"prev  "<<prev<<endl;
		multiset<ll>::iterator it1=mset1.find(prev);
		//typeof(mset1.begin()) it2=it1++;

		mset1.erase(it1);
		//cout<<mset1.count(prev);
		mset1.insert(s[p-1]-s[l]);
		mset1.insert(s[r-1]-s[p]);
		//cout<<mset1.size()<<"  hii   "<<endl;
		it1=mset1.end();
		it1--;
		
		cout<<*it1<<endl;
	}

}