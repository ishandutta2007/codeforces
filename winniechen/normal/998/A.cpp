#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	
	int count = 0;
	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
		count+=arr[i];
	}	
	
	if(n == 1){
		cout << -1 <<endl;
		return 0;
	}
	vector<int> solution;
	int i = 0, sum = 0;
	for (;i<n;i++){
		sum+= arr[i];
		solution.push_back(i+1);
		if ((2*sum )!= count){
			break;
		}
		
	}
	if (i == n-1){
		cout << -1 <<endl;
	}
	else{
		cout << solution.size()<<endl;
		for (int j=0;j<solution.size();j++){
			cout << solution[j] << " ";
		}
	}
	

}