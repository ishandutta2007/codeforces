
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
int check(int answer);
int compute(int answer);
vector< vi > vec(10);
int a[2000];
int fact;
int ans[2000][10]={0};
int vaa[10];   
int main(){
	std::ios::sync_with_stdio(false);
	int i,j,n;
	cin>>n;
	rep(i,8){
		vaa[i]=i;
	}
	fact=1;
	f(i,1,9){
		fact*=i;
	}
	rep(i,n){
		cin>>a[i];
		a[i]--;
		ans[i][a[i]]++;
		vec[a[i]].pb(i);
		rep(j,8){
			if(i!=0)
				ans[i][j]+=ans[i-1][j];
		}
	}
	int high=250;
	int low=1;
	int answ=0;
	int mid=(low+high)/2;
	while(low<=high){
		if(check(mid)){
			answ=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	if(answ==0){
		int counti=0;
		rep(i,8){
			if(!vec[i].empty())
				counti++;
		}
		cout<<counti<<endl;
		return 0;
	}
	//cout<<fact/(6*7*8)<<endl;
	compute(answ);
	//check(0);
}

int check(int answer){
	int i,j,val1;
	sort(vaa,vaa+8);
	rep(i,fact){

		int prev=-1;
		int flag=0;
		rep(j,8){
			//int val=vaa[j];
			if(prev==-1){
				val1 = 0;
			}
			else
				val1=ans[prev][vaa[j]];
			val1+=answer;
			if(vec[vaa[j]].size()<val1){
				flag=1;

				break;
			}
			else
			{
				prev=vec[vaa[j]][val1-1];
			}
		}
		if(flag==0){
			//cout<<"hii";
			return 1;
		}
		next_permutation(vaa,vaa+8);
	}
	return 0;
}


int compute(int answer){
	//cout<<"hii"<<endl;
	int i,j,val1,k,counti=0,valmate;
	int maxi=0;
	sort(vaa,vaa+8);
	rep(i,fact){

		
		 int flag=0;
		f(k,0,1<<8){
			//k=1<<7;
			flag=0;
			counti=0;
			int prev=-1;
			rep(j,8){
			//int val=vaa[j];
				if(prev==-1){
					val1 = 0;
				}
				else
					val1=ans[prev][vaa[j]];
				if((k&(1<<j))!=0)
					valmate=1;
				else
					valmate=0;

				val1+=answer+valmate;
				//cout<<valmate<<"  dasa "<<k<<"  "<<j<<endl;

				counti+=answer+valmate;
				if(vec[vaa[j]].size()<val1){
					flag=1;
					//cout<<"hii";
					break;
				}
				else
				{
					prev=vec[vaa[j]][val1-1];
				}
			}
			
			if(flag==0){
				maxi=max(maxi,counti);
				
			}
			//break;
		}
		
		next_permutation(vaa,vaa+8);
	}
	cout<<maxi<<endl;
}