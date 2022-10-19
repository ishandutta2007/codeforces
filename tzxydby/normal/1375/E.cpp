#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],n;
struct zh
{
	int x,y,z;
	bool operator<(const zh k)const
	{
		return x==k.x?(y==k.y?(z>k.z):(y>k.y)):x<k.x;
	}
	zh(){}
	zh(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};
vector<zh>v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<i;j++)
			if(a[i]<a[j])
				v.push_back(zh(j,a[i],i));
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for(auto i:v)
		printf("%d %d\n",i.x,i.z);
	return 0;
}