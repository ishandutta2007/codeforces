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
int flag=0,ans,n;
int r[10],d[12],l[12],u[12];
int print(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int val;
	cin>>val;
	if(flag){
		if(x1<=l[0] && r[0]<=x2 && y1<=d[0] && u[0]<=y2)
			return val-1;

	}
	return val;
}
int findright(int l,int r){
	//cout<<l<<" fsfds"<<r<<endl;
	if(l>r)
		return 0;
	int mid=(l+r)/2;
	int val=print(1,1,mid,n);
	if(val>0){
		ans=mid;
		findright(l,mid-1);

	}
	else{
		findright(mid+1,r);
	}

	return 0;
}
int findleft(int l,int r,int r1){
	if(l>r)
		return 0;
	int mid=(l+r)/2;
	int val=print(mid,1,r1,n);
	if(val>0){
		ans=mid;
		findleft(mid+1,r,r1);
	}
	else{
		findleft(l,mid-1,r1);
	}


	return 0;
}
int findup(int l,int r,int l1,int r1){
	if(l>r)
		return 0;
	int mid=(l+r)/2;
	int val=print(l1,1,r1,mid);
	if(val>0){
		ans=mid;
		findup(l,mid-1,l1,r1);
	}
	else{
		findup(mid+1,r,l1,r1);
	}

	return 0;
}
int finddown(int l,int r,int l1,int r1,int u1){
	if(l>r)
		return 0;
	int mid=(l+r)/2;
	int val=print(l1,mid,r1,u1);
	if(val>0){
		ans=mid;
		finddown(mid+1,r,l1,r1,u1);
	}
	else{
		finddown(l,mid-1,l1,r1,u1);
	}


	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    cin>>n;
    int r1,l1,u1,d1;
    findright(1,n);
    r1=ans;
    findleft(1,r1,r1);
    l1=ans;
    l[0]=l1;
    r[0]=r1;
    findup(1,n,l1,r1);
    u1=ans;
    finddown(1,u1,l1,r1,u1);
    d1=ans;
    u[0]=u1;
    d[0]=d1;
    flag=1;
    findright(1,n);
    r1=ans;
    findleft(1,r1,r1);
    l1=ans;
    l[1]=l1;
    r[1]=r1;
    findup(1,n,l1,r1);
    u1=ans;
    finddown(1,u1,l1,r1,u1);
    d1=ans;
    u[1]=u1;
    d[1]=d1;
    cout<<"! ";
    rep(i,1){
    	cout<<l[i]<<" "<<d[i]<<" "<<r[i]<<" "<<u[i]<<" ";
    }
    i=1;
    cout<<l[i]<<" "<<d[i]<<" "<<r[i]<<" "<<u[i];

}