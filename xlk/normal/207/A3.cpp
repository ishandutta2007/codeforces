#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
pair<ii,int>a[200020];
long long n,k,c,x,y,m,z,ac,t,b,i;
int main()
{
	for(cin>>n;n--;i++)
		for(cin>>k>>c>>x>>y>>m,t=0;k--;z=max(z,t))
		{
			if(ac<=200000)
				a[ac++]=make_pair(ii(t,c),i);
			b=(c*x+y)%m;
			if(b<c&&k)
				t++;
			c=b;
		}
	cout<<z<<endl;
	if(ac<200001)
	{
		sort(a,a+ac);
		for(int i=0;i<ac;i++)
			cout<<a[i].X.Y<<" "<<a[i].Y+1<<endl;
	}
}