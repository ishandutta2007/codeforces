//raja1999
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
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
	int t;
	//cin>>t;
	t=1;
	while(t--){
		int n,i,fw,bw,c;
		cin>>n;
		c=0;
		if(n<=55){
			i=1;
			c=0;
			fw=0;
			bw=7;
			while(c<=n-2){
				if(i%2){
					cout<<char('a'+fw)<<i<<" ";
					fw++;
					if(fw==8){
						fw=0;
						i++;
					}
				}
				else{
					cout<<char('a'+bw)<<i<<" ";
					bw--;
					if(bw==-1){
						bw=7;
						i++;
					}
				}
				c++;
			}
			if(i%2){
				if(fw!=0)
					cout<<char('a'+fw-1)<<8<<" "<<"h8"<<endl;
				else{
					cout<<char('a'+fw)<<8<<" "<<"h8"<<endl;
				}
			}
			else{
				if(bw!=7){
					if(bw+1!=7)
						cout<<char('a'+bw+1)<<8<<" "<<"h8"<<endl;
					else{
						cout<<char('a'+bw+1)<<7<<" "<<"h8"<<endl;
					}
				}
				else{
					cout<<char('a'+bw)<<7<<" "<<"h8"<<endl;
				}
			}
		}	
		else{
			i=1;
			c=0;
			fw=0;
			bw=7;
			while(c<=53){
				if(i%2){
					cout<<char('a'+fw)<<i<<" ";
					fw++;
					if(fw==8){
						fw=0;
						i++;
					}
				}
				else{
					cout<<char('a'+bw)<<i<<" ";
					bw--;
					if(bw==-1){
						bw=7;
						i++;
					}
				}
				c++;
			}
			if(n==56){
				cout<<"g7 h7 h8"<<endl;
			}
			else{
				cout<<"h7 g7 g8 ";
				c+=3;
				bw=5;
				while(n-c>=1){
					cout<<char('a'+bw)<<8<<" ";
					bw--;
					c++;
				}
				cout<<"h8"<<endl;
			}
		}
	}
}