#include <iostream>
using namespace std;

int main() {
    string s;
    int n,m;
    cin>>n>>m;
    cin>>s;
    int l,r;
    char c1,c2;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r>>c1>>c2;
        for(int j=l-1;j<r;j++)
        {
            if(s[j]==c1)
            {
                s[j]=c2;
            }
        }
    }
    cout<<s;
	return 0;
}