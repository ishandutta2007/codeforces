
#include <bits/stdc++.h>

#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define new cout<<endl
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())

using namespace std;

int main(){
	int n,ans=0;
	cin>>n;
	vector<int> kk(n);
	map<int,int> pos;
	ff(n){
		int x;
		cin>>kk[i];
		pos[kk[x]]=i;
	}
    ff(n){
    	if(kk[i]==i) ++ans;
    }
    
    if(ans==n){
    	cout<<ans<<endl;
    	return 0;
    }
    ff(n){
    	if(kk[i]==i) continue;
    	else{
    		if(i==kk[kk[i]]) {cout<<ans+2<<endl; return 0;}
    	}
    }
    cout<<ans+1;
    return 0;
    return 0;
}