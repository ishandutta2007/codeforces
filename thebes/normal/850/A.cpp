#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define int long long

const double PI=3.1415926535;
const double EPS=1e-6;

double angle(vector<int> &x,vector<int> &y){
	int num=0;
	for(int j=0;j<5;j++)num+=x[j]*y[j];
	double den=1;
	den*=sqrt(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]+x[3]*x[3]+x[4]*x[4]);
	den*=sqrt(y[0]*y[0]+y[1]*y[1]+y[2]*y[2]+y[3]*y[3]+y[4]*y[4]);
	//cout<<sqrt(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]+x[3]*x[3]+x[4]*x[4])<<"\n";
	//cout<<sqrt(y[0]*y[0]+y[1]*y[1]+y[2]*y[2]+y[3]*y[3]+y[4]*y[4])<<"\n";
	//cout<<"num/den is "<<num<<" "<<den<<" "<<(double)num/den<<"\n";
	return acos((double)num/den)*180/PI;
	//cout<<"angle is "<<acos((double)num/den)*180/PI<<"\n";
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	//vector<int> a={0,1,0,0,0};
	//vector<int> b={0,2,0,0,0};
	//cout<<fixed<<setprecision(10);
	//cout<<angle(a,b)<<"\n";
	//cout<<angle(b,a)<<"\n";
	//return 0;
	int n;cin>>n;
	vector<vector<int>> v(n,vector<int>(5));
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++)cin>>v[i][j];
	}
	vector<int> ans;
	//is the i-th point good?
	for(int i=0;i<n;i++){
		vector<vector<int>> al; //all the different vectors
		for(int j=0;j<n;j++){
			if(i==j)continue;
			vector<int> vec(5);
			for(int k=0;k<5;k++)vec[k]=v[j][k]-v[i][k];
			al.push_back(vec);
		}
		bool bad=false;
		if(al.size()>20)bad=true;
		//cout<<"do "<<i<<"\n";
		if(!bad){
			for(int j=0;j<(int)al.size();j++){
				for(int k=j+1;k<(int)al.size();k++){
					if(angle(al[j],al[k])<90-EPS)bad=true;
				}
			}
		}
		if(!bad)ans.push_back(i+1);
	}
	cout<<ans.size()<<"\n";
	for(int i:ans)cout<<i<<"\n";
}