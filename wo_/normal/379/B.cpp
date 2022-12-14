#include<iostream>
#include<string>

using namespace std;

int a[330];
int N;

string ans;

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++){
		if(i!=N-1){
			for(int j=0;j<a[i];j++){
				ans+="PRL";
			}
			ans+="R";
		}
		else{
			for(int j=0;j<a[i];j++){
				ans+="PLR";
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}