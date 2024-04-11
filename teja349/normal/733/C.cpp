
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

int main(){
	int n,i,j,k,z,a[1000],b[1000],dummy,value,valM,valm,maxi,mini,sum[1000]={0},sum1,m,initial;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	cin>>m;
	f(i,1,m+1){
		cin>>b[i];
		sum1+=b[i];
	}
	if(sum1!=sum[n]){
		cout<<"NO";
		return 0;
	}
	j=1;
	initial=0;
	k=0;

	f(i,1,m+1){

		j=initial+1;
		mini=1000*1000*1000;
		maxi=0;
		valM=j;
		valm=j;
		while(b[i]>sum[j]-sum[initial]){
			
			if(maxi<a[j]){
				valM=j;
				maxi=a[j];
			}
			if(mini>a[j]){

				valm=j;
				mini=a[j];
				//cout<<mini<<endl;
			}
			j++;
		}
		//cout<<valM<<"    aghsa   "<<initial+1<<endl;
		if(maxi<a[j]){

				valM=j;
				maxi=a[j];
				//cout<<maxi<<"Dasd"<<endl<<j;
			}
			if(mini>a[j]){

				valm=j;
				mini=a[j];
				//cout<<mini<<endl;
			}
		
		if(b[i]!=sum[j]-sum[initial]){
			cout<<"NO"<<endl;
			return 0;
		}
		if(mini==maxi && j-initial>1){
			//cout<<maxi<<mini;
			cout<<"NO"<<endl;
			return 0;
		}
		initial=j;

	}

	j=1;
	initial=0;
	k=0;
	z=0;
	cout<<"YES"<<endl;

	f(i,1,m+1){
		//cout<<"Sdas"<<i<<endl;

		j=initial+1;
		maxi=0;
		mini=1000*1000*1000;
		valM=j;
		valm=j;
		while(b[i]>sum[j]-sum[initial]){
				//cout<<"SDfsaafhiiiiiii"<<endl;
			if(maxi<a[j]){

				valM=j;
				maxi=a[j];
			}
			if(mini>a[j]){
				valm=j;
				mini=a[j];
			}
			j++;

		}
		//cout<<j<<"  dbgvds "<<endl;
		if(maxi<a[j]){
			//cout<<"byee"<<valM<<j<<endl;
				valM=j;
				maxi=a[j];
			}
			if(mini>a[j]){
				valm=j;
				mini=a[j];
			}

		if(j==initial+1){
			initial=j;
			continue;
		}
		if(valM!=initial+1){
			//cout<<"dadasasd"<<endl;
			k=z;
			value=valM;
			while(valM != (initial+1)){
				cout<<valM-k<<" L"<<endl;
				z++;
				valM--;
				//cout<<valM<<"    aghsa   "<<initial+1<<endl;
				//break;

				
			}
			while(value!=j){
				cout<<valM-k<<" R"<<endl;
				z++;
				value++;
			}

		}
		else{
			dummy=initial+1;
			while(a[initial+1]==a[dummy])
			{
				dummy++;
			}
			valM=dummy-1;
			k=z;
			value=valM;
			//cout<<valM<<"fsdfa    "<<j<<endl;
			while(value!=j){
				cout<<valM-k<<" R"<<endl;
				z++;
				value++;
				//break;
			}
			while(valM!=initial+1){
				cout<<valM-k<<" L"<<endl;
				z++;
				valM--;
				//return 0;
			}


		}
		//cout<<i<<"   meee  "<<endl;
		initial=j;



		

	}



}