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
#define ld long double
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
ld l[212345],r[212345];
ld sy,a,b;
ld pre[212345];
ll x,y;
ld getleft(int mid){
	return (l[mid]*(sy+y)-x*sy)/y;
}
ld getright(int mid){
	return (r[mid]*(sy+y)-x*sy)/y;
}

int checkleft(int mid){
	if(getleft(mid)<=a)
		return 1;
	return 0;
}
int checkright(int mid){
	if(getright(mid)>=b)
		return 1;
	return 0;
}
int main(){
    //std::ios::sync_with_stdio(false);
	
	//cin>>sy>>a>>b;
	scanf("%llf%llf%llf",&sy,&a,&b);
	sy*=-1;
	int n;
	//cin>>n;
	scanf("%d",&n);
	int i;
	f(i,1,n+1){
		//cin>>l[i]>>r[i];
		scanf("%llf%llf",&l[i],&r[i]);
		pre[i]=pre[i-1]+r[i]-l[i];
	}
	int q;
	//cin>>q;
	scanf("%d",&q);
	int xx,yy;
	rep(i,q){
		//cin>>xx>>yy;
		scanf("%d%d",&xx,&yy);
		x=xx;
		y=yy;
		int low=1;
		int high=n;
		int ans=0;
		int mid;
		while(low<=high){
			mid=(low+high)/2;
			if(checkleft(mid)){
				ans=mid;
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		ld fuck=0;
		if(ans!=0){

			fuck+=max(getright(ans),a)-a;
		}

		ll lol=ans;
		low=1;
		high=n;
		ans=n+1;
		while(low<=high){
			mid=(low+high)/2;
			if(checkright(mid)){
				ans=mid;
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}

		fuck+=(pre[ans-1]-pre[lol])*(sy+y)/y;
		if(ans!=n+1){
			fuck+=b-min(getleft(ans),b);
		}
		cout<<setprecision(30)<<fuck<<"\n";
	//	printf("%f\n",fuck);
		

	}


    return 0;  
    
}