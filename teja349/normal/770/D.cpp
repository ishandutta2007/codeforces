#include <bits/stdc++.h>
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
#define endl "\n"
int flag;
int arr[2000];
int papad;
//string str="";
int find_max_level(string s){
	//stack<char> st;
	int i,counter=0,maxi=-1;
	rep(i,s.length()){
		if(s[i]=='[')
			counter++;
		else
			counter--;
		maxi=max(maxi,counter);
	}
	return maxi;
}
string cheker(string s,int val){
	flag=0;
	string str=" ";
	//return str;
	int i,counter=0;
	rep(i,papad+2){
		str+=' ';
		
	}
	//cout<<str<<endl;

	rep(i,s.length()){
		if(s[i]=='['){
			if(counter<val){
				str[arr[i]]='|';
			}
			else if(counter==val){
				flag=1;
				str[arr[i]]='+';
				str[arr[i]+1]='-';
			}

			counter++;
		}
		else{
			counter--;
			if(counter<val){
				str[arr[i]]='|';
			}
			else if(counter==val){
				//cout<<"mew";
				str[arr[i]]='+';
				str[arr[i]-1]='-';
			}
		}

		//maxi=max(maxi,counter);
	}
	//cout<<"nbfb";
	str=str.substr(0,papad);
	cout<<str<<endl;
	//exit(0);
	return str;

}
string computemid(string s){
	int j=0,i;
	string s1="";
	rep(i,s.length()){
		if(s[i]=='['){
			s1+="|";
			arr[i]=j;
			j++;

		}
		else{
			if(s[i-1]=='['){
				s1+="   ";
				j+=3;
				s1+="|";
				arr[i]=j;
				j++;
			}
			else{
				s1+"|";
				arr[i]=j;
				j++;
			}
		}
	}
	papad=j;
	return s1;
}
int main(){
	std::ios::sync_with_stdio(false); 
	int n;
	cin>>n;
	string s;
	cin>>s;
	find_max_level(s);
	string middle=computemid(s);
	int counter=0;
	stack<string> sta;
	flag=1;
	//cout<<arr[0]<<" "<<arr[1]<<endl;
	while(flag){
		//cout<<"lol";
		string str =cheker(s,counter);
		if(flag){
			sta.push(str);
		}
		counter++;
	}
	while(!sta.empty()){
		cout<<sta.top()<<endl;
		sta.pop();
	}

	return 0;
}