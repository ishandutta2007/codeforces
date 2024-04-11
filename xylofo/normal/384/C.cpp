#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> list;
vector<int> sorted;

int main(){
    long long int n,res=0;
    cin>>n;
    long long int count=0;
    for(int i=0; i<n;i++){
        bool tmp;
        cin>>tmp;
        if(!tmp)res+=count;
        else count++;
    }
    cout<<res<<endl;
    return 0;
}