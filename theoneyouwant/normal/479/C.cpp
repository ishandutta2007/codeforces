#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    cin>>n;
    long long int x,y;
    pair <long long int,long long int> a[n];
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        a[i] = make_pair(x,y);
    }
    x=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i].second>=x)
        {
            x=a[i].second;
        }
        else
        {
            x=a[i].first;
        }
    }
    cout<<x;
	// your code goes here
	return 0;
}