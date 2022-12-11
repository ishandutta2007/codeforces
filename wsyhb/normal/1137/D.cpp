#include<bits/stdc++.h>
using namespace std;
int k;
vector<string> S; 
inline void move(vector<int> p)
{
	assert(!p.empty());
	cout<<"next";
	for(int i=0;i<int(p.size());++i)
		cout<<' '<<p[i];
	cout<<endl;
	string opt;
	cin>>opt;
	assert(opt!="stop");
	assert((int)opt.size()==1);
	assert(opt[0]>='0'&&opt[0]<='9');
	k=opt[0]^'0';
	S.resize(k);
	for(int i=0;i<k;++i)
		cin>>S[i];
}
const int arr[]={0,1,2,3,4,5,6,7,8,9};
int main()
{
	ios::sync_with_stdio(false);
	while(k!=2)
	{
		move(vector<int>(arr,arr+2));
		move(vector<int>(1,0));
	}
	while(k!=1)
		move(vector<int>(arr,arr+10));
	cout<<"done"<<endl;
	return 0;
}