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
int haha[312345],baba[312345],lol[312345],papa[312345];
//int bmin[312345],bmax[312345],pmin[312345],pmax[312345];
int a[312345];
stack<int> st1,st2,auxst2,auxst1,countst1,countst2;
int cou1,cou2;
int getmin(){
	int mini=inf;
	if(!st1.empty()){
		mini=min(mini,auxst1.top());
	}
	if(!st2.empty()){
		mini=min(mini,auxst2.top());
	}
	return mini;
}
int getans(){

	int ans=0,mini=inf;
	if(!st1.empty()){
		mini=min(mini,auxst1.top());
		ans=countst1.top();
	}
	if(!st2.empty()){
		if(mini==auxst2.top())
			ans+=countst2.top();
		else if(mini>auxst2.top())
			ans=countst2.top();
	}
	return ans;
}

int addelem(int val){
	if(st1.empty()){
		st1.push(val);
		auxst1.push(val);
		countst1.push(1);
		return 0;
	}
	st1.push(val);
	if(val==auxst1.top()){
		auxst1.push(val);
		countst1.push(countst1.top()+1);
	}
	else if(val>auxst1.top()){
		auxst1.push(auxst1.top());
		countst1.push(countst1.top());
	}
	else{
		auxst1.push(val);
		countst1.push(1);
	}
	return 0;
}
int removelem(){
	if(!st2.empty()){
		st2.pop();
		auxst2.pop();
		countst2.pop();
		return 0;
	}
	while(!st1.empty()){
		if(st2.empty()){
			st2.push(st1.top());
			auxst2.push(st1.top());
			countst2.push(1);
		}
		else{
			st2.push(st1.top());
			if(st1.top()==auxst2.top()){
				auxst2.push(st1.top());
				countst2.push(countst2.top()+1);
			}
			else if(st1.top()>auxst2.top()){
				auxst2.push(auxst2.top());
				countst2.push(countst2.top());
			}
			else{
				auxst2.push(st1.top());
				countst2.push(1);
			}
		}
		st1.pop();
		auxst1.pop();
		countst1.pop();
		

	}
	if(!st2.empty()){
		st2.pop();
		auxst2.pop();
		countst2.pop();
		return 0;
	}
	return 0;


}
int update(int val,int type){
	if(type==0){
		if(cou1<cou2){
			removelem();
		}
		else if(cou1>=cou2){
			addelem(haha[cou1]-cou1);
		}

	}
	else{
		if(cou2<cou1){
			removelem();
		}
		else if(cou2>=cou1){
			addelem(-lol[cou2]-cou2);
		}
	}
}
ll compute(int st,int en){
	int mid=(st+en)/2;
	//cout<<mid<<endl;
	haha[mid+1]=a[mid+1];
	lol[mid+1]=a[mid+1];
	//cout<<haha[mid+1]<<endl;
	int i=mid+1;
	
	// bmax[en+1]=inf;
	// bmin[en+1]=inf;
	// baba[en+1]=inf;	
	f(i,mid+2,en+1){
		haha[i]=max(haha[i-1],a[i]);
		lol[i]=min(lol[i-1],a[i]);	
	}

	fd(i,en,mid+1){
		baba[i]=haha[i]-lol[i]-i;
		if(baba[i] == baba[i+1]){
			papa[i]=papa[i+1]+1;
		}
		else if(baba[i]<baba[i+1]){
			papa[i]=1;
		}
		else{
			baba[i]=baba[i+1];
			papa[i]=papa[i+1];
		}

		// bmin[i]=-lol[i]-i;
		// if(bmin[i] == bmin[i+1]){
		// 	pmin[i]=pmin[i+1]+1;
		// }
		// else if(bmin[i]<bmin[i+1]){
		// 	pmin[i]=1;
		// }
		// else{
		// 	bmin[i]=bmin[i+1];
		// 	pmin[i]=pmin[i+1];
		// }


		// bmax[i]=haha[i]-i;
		// if(bmax[i] == bmax[i+1]){
		// 	pmax[i]=pmax[i+1]+1;
		// }
		// else if(bmax[i]<bmax[i+1]){
		// 	pmax[i]=1;
		// }
		// else{
		// 	bmax[i]=bmax[i+1];
		// 	pmax[i]=pmax[i+1];
		// }

	}
	while(!st1.empty()){
		st1.pop();
		auxst1.pop();
		countst1.pop();
	}
	while(!st2.empty()){
		st2.pop();
		auxst2.pop();
		countst2.pop();
	}

	cou1=mid+1,cou2=mid+1;
	ll ans=0,val;
	int mini=inf;
	int maxi=0;
	fd(i,mid,st){
		mini=min(mini,a[i]);
		maxi=max(maxi,a[i]);
		while(cou1<=en && lol[cou1]>=mini){
			update(cou1,0);
			cou1++;

		}
		
		while(cou2<=en && haha[cou2]<=maxi){
			update(cou2,1);
			cou2++;
		}
		
		
		val=maxi-mini+i;
		
		if(val>mid && val<min(cou1,cou2)){
			
			ans++;
		}
		//cout<<i<<" "<<cou1<<" "<<cou2<<" "<<ans<<endl;
		if(cou1>cou2){
			if(getmin()-mini==-i){
				ans+=getans();
			}
			
			//cout<<i<<" dsdss "<<cou1<<" "<<cou2<<" "<<getmin()<<endl;
		}
		else{
			
			if(getmin()+maxi==-i){
				ans+=getans();
			}
			
			
		}
		val=max(cou2,cou1);
		//cout<<i<<" "<<cou1<<" "<<cou2<<" "<<ans<<endl;
		if(baba[val]==-i){
			ans+=papa[val];
		}
		//cout<<i<<" "<<cou1<<" "<<cou2<<" "<<ans<<endl;
		//cout<<ans<<endl;
	}

	return ans;




}   
ll calc(int st,int en){
	int mid=(st+en)/2;
	if(st==en){
		return 1;
	}

	ll sumi=0;

	sumi=calc(st,mid);
	//cout<<st<<" "<<en<<" "<<mid<<endl;
	//cout<<sumi<<endl;
	sumi+=calc(mid+1,en);
	//cout<<st<<" "<<en<<" "<<mid<<endl;
	//cout<<sumi<<endl;
	sumi+=compute(st,en);
	//cout<<st<<" "<<en<<" "<<mid<<endl;
	//cout<<sumi<<endl;
	return sumi;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n,u,v;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>u>>v;
    	a[u]=v;

    }
    //cout<<compute(1,n)<<endl;
   cout<<calc(1,n)<<endl;

    return 0;      

}