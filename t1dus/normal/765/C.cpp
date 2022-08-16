/*input
11 11 5
*/
     
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
#define boost ios_base::sync_with_stdio(0),cin.tie(0)     
using namespace std;


bool yes(int k,int a,int b){
	if(a%k && b<k) return false;
	else if(a<k && b%k) return false;
	else if(a<k && b<k) return false;
	

	return true;
}
int main(){
	boost;
	int a,b,c,k;
	cin>>k>>a>>b;
	if(yes(k,a,b))
		cout<<(a/k)+(b/k)<<endl;
	else
		cout<<-1<<endl; 
}