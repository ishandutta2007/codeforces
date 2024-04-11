#include<iostream>
#include<stack>
using namespace std;
#define ll long long

ll n;
char ch[10];

struct node{
	ll num,cnt;
};
stack<node> st;

int main(){
	cin>>n;
	st.push((node){1,0});
	while(n--){
		cin>>ch;
		if(ch[0]=='f'){
			ll a;
			cin>>a;
			st.push((node){a,0});
		}
		else if(ch[0]=='e'){
			ll tmp=st.top().num*st.top().cnt;
			st.pop();
			st.top().cnt+=tmp;
			if(st.top().cnt>=1ll*4294967296){
				cout<<"OVERFLOW!!!";
				return 0;
			}
		}
		else
			st.top().cnt++;
	}
	if(st.top().cnt>=1ll*4294967296){
		cout<<"OVERFLOW!!!";
		return 0;
	}
	cout<<st.top().cnt;
}