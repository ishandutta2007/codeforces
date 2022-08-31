#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vb vector< bool >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define sort(a) sort(a.begin(),a.end())
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define moddd (1000*1000*1000+9)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define endl "\n"
#define flush fflush(stdout) 
#define pi 3.14159265358979323846264338327950
#define primeDEN 727999983
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int findchar(vi &freq,int pre){
	int i;
	for(i=pre;i<freq.size();i++){
		if(freq[i]!=0) break;
	}
	freq[i]-=2;
	return i;
}

int main(){
	std::ios::sync_with_stdio(false); 
	int n;
	cin>>n;
	string str;
	cin>>str;
	vi freq(300,0);
	int i;
	for(i=0;i<str.length();i++){
		freq[str[i]]++;
	}
	int oddcnt=0;
	vi oddchars;
	for(i=0;i<freq.size();i++){
		if(freq[i]%2!=0){
			oddcnt++;
			oddchars.pb(i);
		}
	}
	if(oddcnt==0){
		string ans;
		ans.resize(n);
		cout<<"1"<<endl;
		int pre=0;
		for(i=0;i<300;i++){
			while(freq[i]!=0){
				freq[i]-=2;
				ans[pre]=i;
				ans[n-pre-1]=i;
				pre++;
			}
		}
		cout<<ans;
		return 0;
	}
	vi factors;
	for(i=1;i<=n;i+=2){
		if(n%i==0) factors.pb(i);
	}
	for(i=factors.size()-1;i>=0;i--){
		int sz=factors[i];
		int num=n/factors[i];
		if(num<oddcnt) continue;
		if((num-oddcnt)%2==1) continue;
		vector<string> strarr(num);
		int j,k;
		for(j=0;j<num;j++){
			strarr[j].resize(sz);
		}
		for(j=0;j<oddcnt;j++){
			strarr[j][sz/2]=oddchars[j];
			freq[oddchars[j]]--;
		}
		int prechar=0;
		for(j=0;j<num;j++){
			int pre=0;
			while(pre!=sz/2){
				//cout<<pre<<" "<<sz/2<<endl;
				int abc=findchar(freq,prechar);
				prechar=abc;
				strarr[j][pre]=abc;
				strarr[j][sz-pre-1]=abc;
				pre++;
			}
		}
		//
		vi vec;
		//return 0;
		for(i=0;i<freq.size();i++){
			// if(freq[i]<0){
			// 	cout<<freq[i]<<endl;
			// 	char ch=i;
			// 	cout<<ch<<endl;
			// 	break;
			// 	abort();
			// }
			while(freq[i]!=0){
				//cout<<freq[i]<<endl;
				vec.pb(i);
				freq[i]--;
			}
		}
		//printvec(vec);
		int eee=0;
		for(j=oddcnt;j<num;j++){
			strarr[j][sz/2]=vec[eee++];
		}
		cout<<num<<endl;
		for(i=0;i<num;i++){
			cout<<strarr[i]<<" ";
		}
		return 0;
	}
	return 0;
}