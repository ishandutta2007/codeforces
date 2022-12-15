#include<iostream>
#include<map>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n][2];
    map <int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        m[a[i][0]]=0;
    }   
    for(int i=0;i<n;i++)
    {
        m[a[i][0]]++;
    }
    int home,away;
    for(int i=0;i<n;i++)
    {
        home=n-1+m[a[i][1]];
        away = 2*(n-1)-home;
        cout<<home<<" "<<away<<endl;
    }
    
    
    return 0;
}