#include <iostream>
using namespace std;
int n;
int main(void){
    int i,j;
    cin>>n;
    for(i=j=1;i<n;i++)
        cout<<((j+=i)%n?j%n:n)<<" ";
    return 0;
}