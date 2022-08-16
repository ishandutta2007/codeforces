
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   

int main(){
	std::ios::sync_with_stdio(false);
	ll a,b,c,m,i,val;
	vl usb,ps;
	string str;
	cin>>a>>b>>c>>m;
	rep(i,m){
		cin>>val;
		cin>>str;
		if(str[0]=='U'){
			usb.pb(val);
		}
		else{
			ps.pb(val);
			//cout<<"ddasa";
		}
	}
	sort(usb.begin(),usb.end());
	sort(ps.begin(),ps.end());
	int maxusb=usb.size();
	int maxps=ps.size();
	int cousb=0;
	int cops=0;
	int ans=0;
	ll sumi=0;
	while(b>0 && cops<maxps){
		//cout<<"gdg";
		b--;
		ans++;
		sumi+=ps[cops];
		cops++;
	}
	//cout<<cops<<endl;
	while(a>0&& cousb<maxusb){
		a--;
		ans++;
		sumi+=usb[cousb];
		cousb++;
	}
	while(c>0 && (cops<maxps || cousb<maxusb)){
	//	cout<<"gsds"<<endl;
		c--;
		if(cousb==maxusb){

			ans++;
			sumi+=ps[cops];
			cops++;

		}
		else if(cops==maxps){
			ans++;
			sumi+=usb[cousb];
			cousb++;
			//cout<<"asa";
		}
		else{
			
			if(usb[cousb]<ps[cops]){
				ans++;
				sumi+=usb[cousb];
				cousb++;
			}
			else{
				ans++;
				sumi+=ps[cops];
				cops++;
			}
		}
	}
	cout<<ans<<" "<<sumi<<endl;
}