#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
lli a[100009],b[100009],p,i,n;
bool check(double t){
	double tt=0;
	for(i=1;i<=n;i++){
		tt+=max(0.0,(a[i]*t-b[i])/p);
	}
	if(tt<=t) return true;
	else return false;
}
int main()
{
ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>p;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	double lo=0,hi=1e12;
	for(int i=0;i<200;i++){
		//cout<<lo<<' '<<hi<<endl;
		double md=(lo+hi)/2.0;
		if(check(md)) lo=md;
		else hi=md;
	}
	if(abs(lo-1e12)/lo<=1e-5) cout<<-1;
	else cout<<fixed<<setprecision(5)<<lo;
}