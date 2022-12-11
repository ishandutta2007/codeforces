#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,m,l,r,a[100],sl,sr,i;
    cin>>n>>m>>l>>r;
    for(i=0;i<m;i++) cin>>a[i];
    sl=1;sr=1;
    for(i=0;i<m;i++)
    {
        if ((a[i]<l)||(a[i]>r)) {cout<<"Incorrect";return 0;}
        if (a[i]==l) sl=0;
        if(a[i]==r) sr=0;
    }
    if (n-m>=sl+sr) cout<<"Correct";else cout<<"Incorrect";
}