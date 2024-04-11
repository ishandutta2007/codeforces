#include<iostream>
#include<algorithm>
using namespace std;
string a[105];
string b[105];
int ac[300],bc[300],v[300];
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],ac[a[i][0]]++;
	for(int i=0;i<n;i++)
		cin>>b[i],bc[b[i][0]]++;
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0,j;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(!v[j]&&(bc[b[j][0]]>ac[b[j][0]]||a[i][0]==b[j][0])&&!(b[j][0]<a[i][0]&&ac[a[i][0]]<=bc[a[i][0]]))
				break;
		v[j]=1,ac[a[i][0]]--,bc[b[j][0]]--;
		if(i)
			cout<<", ";
		cout<<a[i]<<" "<<b[j];
	}
	return 0;
}