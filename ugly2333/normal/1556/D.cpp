//CF1556D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 11111;
int n,k,a[N];
pair<int,int> query(int i,int j){
	int x,y;
	cout<<"and "<<i<<' '<<j<<endl;
	cin>>x;
	cout<<"or "<<i<<' '<<j<<endl;
	cin>>y;
	return make_pair(x,y);
}
int main()
{
	int i;
	pair<int,int> p12,p13,p23,p;
	cin>>n>>k;
	p12=query(1,2);
	p13=query(1,3);
	p23=query(2,3);
	a[1]=p12.first|p13.first|((~p23.second)&p12.second);
	for(i=2;i<=n;i++){
		if(i<=3){
			if(i==2)
				p=p12;
			else
				p=p13;
		}
		else
			p=query(1,i);
		a[i]=(a[1]&p.first)|((~a[1])&p.second);
	}
	sort(a+1,a+n+1);
	cout<<"finish "<<a[k]<<endl;
	return 0;
}