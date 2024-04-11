#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k,h[2020];
string s[2020];
vector<int>F(int l,int r)
{
	if(l+1==r)
		return vector<int>(2,0);
	int m=min_element(h+l+1,h+r)-h;
	vector<int>L=F(l,m),R=F(m,r),z(r-l+1,0);
	for(int i=0;i<L.size();i++)
		for(int j=0;j<R.size();j++)
			z[i+j]=max(z[i+j],L[i]+h[m]*i*j+R[j]);
	return z;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n);
	for(int i=1;i<n;i++)
		for(;h[i]<s[i-1].size()&&h[i]<s[i].size()&&s[i-1][h[i]]==s[i][h[i]];h[i]++)
			;
	cout<<F(0,n)[k];
	return 0;
}