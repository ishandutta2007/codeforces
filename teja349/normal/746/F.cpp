//teja349
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
#define pqueue priority_queue< pii >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
set<pii> seti,setfull;
set<pii> ::iterator it1,it,it2;
int arr[212345]={0};
int a[212345]={0};
int t[212345]={0};
int main(){
	std::ios::sync_with_stdio(false);
	int n,w,k;
	cin>>n>>w>>k;
	int i=0;
	int j=0;
	ll plea=0;
	ll total=0;
	ll totalnew=0;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		cin>>t[i];
	}
	i=0;
	j=0;
	ll maxi=0;
	ll val;
	while(j<n){

		if(seti.size()<w){
			if(total+(t[j]+1)/2<=k){
				seti.insert(mp((t[j]+1)/2,j));
				arr[j]=1;
				total+=(t[j]+1)/2;
				plea+=a[j];
				j++;
			}
			else{
				if(arr[i]==1){
					seti.erase(mp((t[i]+1)/2,i));
					plea-=a[i];
					total-=(t[i]+1)/2;
					arr[i]=0;
					// if(!setfull.empty()){
					// 	it=setfull.end();
					// 	it--;
					// 	val=it->ss;
					// 	arr[val]=1;
					// 	setfull.erase(it);
					// 	total-=t[val];
					// 	total+=(t[val]+1)/2;
					// 	seti.insert(mp((t[val]+1)/2,val));
					// }

				}
				else{
					j++;
				}
				i++;
			}
		}
		else{
			it=seti.begin();
			int val=it->ss;
			if(t[val]<t[j]){
				totalnew=total+(t[val])-(t[val]+1)/2+(t[j]+1)/2;
				if(totalnew<=k){
					seti.erase(it);
					setfull.insert(mp(t[val],val));
					arr[val]=0;
					plea+=a[j];
					total=totalnew;
					seti.insert(mp((t[j]+1)/2,j));
					arr[j]=1;
					j++;
				}
				else{
					if(arr[i]==1){
						seti.erase(mp((t[i]+1)/2,i));
						plea-=a[i];
						total-=(t[i]+1)/2;
						if(!setfull.empty()){
							it=setfull.end();
							it--;
							val=it->ss;
							arr[val]=1;
							arr[i]=0;
							setfull.erase(it);
							total-=t[val];
							total+=(t[val]+1)/2;
							seti.insert(mp((t[val]+1)/2,val));
						}


					}
					else{
						setfull.erase(mp(t[i],i));
						plea-=a[i];
						total-=t[i];

					}
					i++;
				}
			}
			else{
				totalnew=total+t[j];
				if(totalnew<=k){
					//setfull.erase(it);
					setfull.insert(mp(t[j],j));
					plea+=a[j];
					total+=t[j];
					//seti.insert((t[j]+1)/2,j);
					j++;
				}
				else{
					if(arr[i]==1){
						seti.erase(mp((t[i]+1)/2,i));
						plea-=a[i];
						total-=(t[i]+1)/2;
						arr[i]=0;
						if(!setfull.empty()){
							it=setfull.end();
							it--;
							val=it->ss;
							arr[val]=1;
							setfull.erase(it);
							total-=t[val];
							total+=(t[val]+1)/2;
							seti.insert(mp((t[val]+1)/2,val));
						}


					}
					else{
						setfull.erase(mp(t[i],i));
						plea-=a[i];
						total-=t[i];

					}
					i++;
				}
			}
			
		}
		maxi=max(maxi,plea);
	}
	cout<<maxi<<endl;
}