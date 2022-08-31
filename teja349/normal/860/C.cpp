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
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


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

int printfiles(int s1,string s2){
	cout<<"move "<<s1<<" "<<s2<<endl;
	return 0;
}
int printfiles(string s1,int s2){
	cout<<"move "<<s1<<" "<<s2<<endl;
	return 0;
}
int printfiles(string s1,string s2){
	cout<<"move "<<s1<<" "<<s2<<endl;
	return 0;
}
int printfiles(int s1,int s2){
	cout<<"move "<<s1<<" "<<s2<<endl;
	return 0;
}
int n;
int check(string s){
	if(s[0]=='0'){
		return -1;
	}
	int i,ans=0;
	rep(i,s.length()){
		if('0'>s[i]	|| s[i]>'9')
			return -1;
		ans*=10;
		ans+=(s[i]-'0');
	}
	if(ans>n)
		return -1;
	return ans;
}
string name[123456];
int typ[123456];
set<int> exset,sysset,swapsysset,swapexset;
vector<string> wrongexam,wrongsys;
int main(){
	std::ios::sync_with_stdio(false);
	//int n;
	cin>>n;
	int i;
	int sumi=0;
	rep(i,n){
		cin>>name[i]>>typ[i];
		sumi+=typ[i];
		
	}
	rep(i,sumi){
		exset.insert(i+1);
	}
	f(i,sumi,n){
		sysset.insert(i+1);
	}
	int val,lol=n,haha=0;
	rep(i,n){
		if(typ[i]==1){
			val=check(name[i]);
			if(val==-1){
				wrongexam.pb(name[i]);
			}
			else if(val>sumi){
				//examswap.pb(val);
				sysset.erase(val);
				swapsysset.insert(val);
			}
			else{
				lol--;
				//seti.erase(i);
				exset.erase(val);
			}

		}
		else{
			val=check(name[i]);
			if(val==-1){
				wrongsys.pb(name[i]);

			}
			else if(val<=sumi){
				//sysswap.pb(val);
				exset.erase(val);
				swapexset.insert(val);
			}
			else{
				haha--;
				//set.erase(i);
				sysset.erase(val);
			}
		}

	}
	if(lol+haha==0){
		cout<<0<<endl;
		return 0;
	}
	set<int>::iterator it,it1;
	if(wrongexam.empty() && wrongsys.empty()){
		cout<<lol+haha+1<<endl;
		it=swapsysset.begin();
		sysset.insert(*it);
		printfiles(*it,"foo");
		wrongexam.pb("foo");
		swapsysset.erase(*it);

	}
	else{
		cout<<lol+haha<<endl;
	}
	
	int varsys=0,varex=0;
	while(lol+haha){
		lol--;	
		if(!sysset.empty()){
			it1=sysset.begin();
			if(!swapexset.empty()){
				it=swapexset.begin();
				printfiles(*it,*it1);
				exset.insert(*it);
				swapexset.erase(*it);
				sysset.erase(*it1);
			}
			else{
				printfiles(wrongsys[varsys],*it1);
				sysset.erase(*it1);
				varsys++;
			}
		}
		else if(!exset.empty()){
			it1=exset.begin();
			if(!swapsysset.empty()){
				it=swapsysset.begin();
				printfiles(*it,*it1);
				sysset.insert(*it);
				swapsysset.erase(*it);
				exset.erase(*it1);
			}
			else{
				printfiles(wrongexam[varex],*it1);
				exset.erase(*it1);
				varex++;
			}
		}
	}
	return 0;


}