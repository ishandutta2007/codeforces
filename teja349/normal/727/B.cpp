
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


int main(){
	string s;
	ll cents=0,doll=0,j,k;
	cin>>s;
	int i;
	fd(i,s.length()-1,0){
		if('0'<=s.at(i)&&s.at(i)<='9'){

			j=i;
			if((i-2>=0 && s.at(i-2)=='.'))
			{	
				if(s.at(i)=='0'&&s.at(i-1)=='0');
				else if(s.at(i-1)=='0'){
					char buff[100];
					strcpy(buff,(s.substr(i,1)).c_str());
					cents+=atoi(buff);
				}
				else{
					char buff[100];
					strcpy(buff,(s.substr(i-1,2)).c_str());
					cents+=atoi(buff);
				}
				i=i-3;
				j=i;
				k=1;

				while(('0'<=s.at(i)&&s.at(i)<='9')||s.at(i)=='.'){
					if(s.at(i)=='.'){
						i--;
						continue;
					}
					char buff[100];
					strcpy(buff,(s.substr(i,1)).c_str());
					doll+=(atoi(buff))*k;
					k*=10;
					i--;

				}
			}
			else{
				//cout<<"hii";
				j=i;
				k=1;
				while(('0'<=s.at(i)&&s.at(i)<='9')||s.at(i)=='.'){
					if(s.at(i)=='.'){
						i--;
						continue;
					}
					char buff[100];
					strcpy(buff,(s.substr(i,1)).c_str());
					doll+=(atoi(buff))*k;
					k*=10;
					i--;

				}
			}
			

			
		}
	}
	int a[1000];k=0;
	i=0;
	doll+=cents/100;
	int val=doll;
	cents=cents%100;
	
	while(doll!=0){
		if(k==3)
		{
			//cout<<"hii";
			k=0;
			a[i++]=14;
			continue;
		}
		a[i++]=doll%10;
		doll/=10;
		k++;
	}

	fd(j,i-1,0){
		if(a[j]==14)
			cout<<".";
		else
			cout<<a[j];
	}
	if(val==0)
		cout<<0;
	if(cents>0)
		cout<<"."<<cents/10<<cents%10<<endl;
}