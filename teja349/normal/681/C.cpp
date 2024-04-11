
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
string str[1000*1000+3];int arr[1000*1000+3];
int main(){
	std::ios::sync_with_stdio(false);
	int n,i=0,j=0,val;
	int k=0;
	string s;
	cin>>n;
	pdqueue pq;
	rep(k,n){
		cin>>s;
		
		if(s[0]=='i'){
			cin>>val;
			pq.push(val);
			//cout<<s<<" "<<val<<endl;
			str[i++]=s;
			arr[j++]=val;
		}
		else if(s[0]=='r'){
			if(pq.size()!=0){
				pq.pop();
				//cout<<s<<endl;
				str[i++]=s;
			}
			else{
			//	cout<<"insert"<<" "<<1<<endl;
				str[i++]="insert";
				arr[j++]=1;
				str[i++]=s;
			}
		}
		else{
			cin>>val;
			while( pq.size()!=0 && pq.top()<val){
				str[i++]="removeMin";

				pq.pop();
			}

			if(pq.size()==0 || pq.top()!=val){
				pq.push(val);
				//cout<<"insert "<<val<<endl;
				str[i++]="insert";
				arr[j++]=val;
			}
			str[i++]=s;
			arr[j++]=val;
		}
	}
	cout<<i<<endl;
	k=0;
	j=0;
	while(k<i){
		cout<<str[k];
		if(str[k][0]!='r'){
			cout<<" "<<arr[j];
			j++;
		}
		k++;
		cout<<endl;


	}
	return 0;
}