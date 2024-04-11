
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
	char a[3][3],ch,chr='2';
	int i,j,ch1=0,ch2=0;
	rep(i,3){
		rep(j,3){
			cin>>a[i][j];
			if(a[i][j]=='X')
				ch1++;
			else if(a[i][j]=='0')
				ch2++;
		}
	}
	if(ch1!=ch2&&ch1!=ch2+1){
		cout<<"illegal"<<endl;
		return 0;
	}
	rep(i,3){

		ch=a[i][0];
		rep(j,3){
			if(ch!=a[i][j])
				break;
		}
		if(j==3)
		{
			if(ch=='X'){
				if(chr=='2')
					chr=ch;
				else if(chr!=ch){
					//cout<<chr<<ch<<endl;
					cout<<"illegal"<<endl;
					return 0;
				}
				else{
					if(ch1==ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}
					
					cout<<"the first player won"<<endl;
					return 0;
				}
			}

			else if(ch=='0'){
				if(chr=='2')
					chr=ch;
				else if(chr!=ch){
					cout<<"illegal"<<endl;
					return 0;
				}
				else{
					if(ch1>ch2)
					{
						cout<<"illegal"<<endl;
						return 0;
					}
					cout<<"the second player won"<<endl;
					return 0;
				}
			}
		}
	}
	if(chr=='X'){
		if(ch1==ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}

		cout<<"the first player won"<<endl;
		return 0;
	}
	else if(chr=='0'){
		if(ch1>ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}
		cout<<"the second player won"<<endl;
		return 0;
	}
	chr='2';
	rep(i,3){

		 ch=a[0][i];
		rep(j,3){
			if(ch!=a[j][i])
				break;
		}
		if(j==3)
		{
			if(ch=='X'){
				if(chr=='2')
					chr=ch;
				else if(chr!=ch){
					cout<<"illegal"<<endl;
					return 0;
				}
				else{
					if(ch1==ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}
					cout<<"the first player won"<<endl;
					return 0;
				}
			}

			else if(ch=='0'){
				if(chr=='2')
					chr=ch;
				else if(chr!=ch){
					cout<<"illegal"<<endl;
					return 0;
				}
				else{
					if(ch1>ch2)
					{
						cout<<"illegal"<<endl;
						return 0;
					}
					cout<<"the second player won"<<endl;
					return 0;
				}
			}
		}
	}
	if(chr=='X'){
		if(ch1==ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}
		cout<<"the first player won"<<endl;
		return 0;
	}
	else if(chr=='0'){
		if(ch1>ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}
		cout<<"the second player won"<<endl;
		return 0;
	}

	rep(j,3){
		 ch=a[0][0];
		if(ch!=a[j][j])
			break;
	}
	if(j==3)
	{
		if(ch=='X'){
			if(ch1==ch2)
			{
				cout<<"illegal"<<endl;
				return 0;
			}
			cout<<"the first player won"<<endl;
			return 0;
		}
		else if(ch=='0'){
			if(ch1>ch2)
			{
				cout<<"illegal"<<endl;
				return 0;
			}
			cout<<"the second player won"<<endl;
			return 0;
		}
	}
	rep(j,3){
		 ch=a[0][2];
		if(ch!=a[j][2-j])
			break;
	}
	if(j==3)
	{
		if(ch=='X'){
			if(ch1==ch2)
		{
			cout<<"illegal"<<endl;
			return 0;
		}
				cout<<"the first player won"<<endl;
			return 0;
		}
		else if(ch=='0'){
			if(ch1>ch2)
			{
				cout<<"illegal"<<endl;
				return 0;
			}
			cout<<"the second player won"<<endl;
			return 0;
		}
	}
	if(ch1+ch2==9)
	{
		cout<<"draw"<<endl;
		return 0;
	}
	else if(ch1==ch2){
		cout<<"first"<<endl;
	}
	else{
		cout<<"second";
	}




}